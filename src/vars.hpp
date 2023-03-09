/* == VARS.HPP ============================================================= */
/* ######################################################################### */
/* ## MS-ENGINE              Copyright (c) MS-Design, All Rights Reserved ## */
/* ######################################################################### */
/* ## This class will take a string and split it into tokens seperated by ## */
/* ## the specified delimiter and split again into sorted key/value pairs ## */
/* ## for fast access by key name.                                        ## */
/* ######################################################################### */
/* ========================================================================= */
#pragma once                           // Only one incursion allowed
/* -- Module namespace ----------------------------------------------------- */
namespace IfVars {                     // Keep declarations neatly categorised
/* -- Includes ------------------------------------------------------------- */
using namespace IfError;               // Using error interface
/* -- Vars class ----------------------------------------------------------- */
template<class MapType>class VarsBase :
  /* -- Base classes ------------------------------------------------------- */
  public MapType                       // Derive by specified map type
{ /* --------------------------------------------------------------- */ public:
  void VarsPushPair(const string &strKey, const string &strValue)
    { this->insert({ strKey, strValue }); }
  void VarsPushPair(const string &strKey, string &&strValue)
    { this->insert({ strKey, move(strValue) }); }
  void VarsPushPair(string &&strKey, const string &strValue)
    { this->insert({ move(strKey), strValue }); }
  void VarsPushPair(string &&strKey, string &&strValue)
    { this->insert({ move(strKey), move(strValue) }); }
  /* -- Insert new key if we don't have it --------------------------------- */
  void VarsPushIfNotExist(const string &strKey, const string &strValue)
    { if(this->find(strKey) == this->end())
        VarsPushPair(strKey, strValue); }
  void VarsPushIfNotExist(string &&strKey, const string &strValue)
    { if(this->find(strKey) == this->end())
        VarsPushPair(move(strKey), strValue); }
  void VarsPushIfNotExist(const string &strKey, string &&strValue)
    { if(this->find(strKey) == this->end())
        VarsPushPair(strKey, move(strValue)); }
  void VarsPushIfNotExist(string &&strKey, string &&strValue)
    { if(this->find(strKey) == this->end())
        VarsPushPair(move(strKey), move(strValue)); }
  /* -- Value access by key name ------------------------------------------- */
  const string &operator[](const string &strKey) const
  { // Find key and return empty string or value
    typedef typename MapType::const_iterator VarsBaseIterator;
    const VarsBaseIterator vIter{ this->find(strKey) };
    if(vIter != this->end()) return vIter->second;
    XC("No such key in table!", "Key", strKey, "Count", this->size());
  }
  /* -- Converts the variables to a string --------------------------------- */
  const string VarsImplodeEx(const string &strSep, const string &strSuf) const
  { // String to return
    ostringstream osS;
    // For each key/value pair, implode it into a string
    for(const auto &vlI : *this)
      osS << vlI.first << strSep << vlI.second << strSuf;
    // Return what we created
    return osS.str();
  }
  /* ----------------------------------------------------------------------- */
  void VarsPushLine(const string &strS, const size_t stSegStart,
    const size_t stSegEnd, const char cDelimiter)
  { // Look for separator and if found?
    const size_t stSepLoc =
      FindCharForwards(strS, stSegStart, stSegEnd, cDelimiter);
    if(stSepLoc != string::npos)
    { // Find start of keyname and if found?
      const size_t stKeyStart =
        FindCharNotForwards(strS, stSegStart, stSepLoc);
      if(stSepLoc != string::npos)
      { // Find end of keyname and if found?
        const size_t stKeyEnd =
          FindCharNotBackwards(strS, stSepLoc-1, stSegStart);
        if(stKeyEnd != string::npos)
        { // Find start of value name and if found?
          const size_t stValStart =
            FindCharNotForwards(strS, stSepLoc+1, stSegEnd);
          if(stValStart != string::npos)
          { // Find end of value name and if found? We can grab key/value
            const size_t stValEnd =
              FindCharNotBackwards(strS, stSegEnd-1, stValStart);
            if(stValEnd != string::npos) return VarsPushPair(
              move(strS.substr(stKeyStart, stKeyEnd-stKeyStart+1)),
              move(strS.substr(stValStart, stValEnd-stValStart+1)));
          } // Could not prune suffixed whitespaces on value.
        }  // Could not prune prefixed whitespaces on value.
      }  // Could not prune suffixed whitespaces on key.
    } // Could not prune prefixed whitespaces on key. Add full value for debug
    return VarsPushPair(Append('#', this->size()),
      move(strS.substr(stSegStart, stSegEnd-stSegStart)));
  }
  /* -- Initialise or add entries from a string ---------------------------- */
  VarsBase(const string &strS, const string &strLS, const char cDelimiter)
  { // Ignore if any of the variables are empty
    if(strS.empty() || strLS.empty()) return;
    // Location of next separator
    size_t stStart = 0;
    // Until eof, push each item split into list
    for(size_t stLoc; (stLoc = strS.find(strLS, stStart)) != string::npos;
                     stStart = stLoc + strLS.length())
      VarsPushLine(strS, stStart, stLoc, cDelimiter);
    // Push remainder of string if available
    VarsPushLine(strS, stStart, strS.length(), cDelimiter);
  }
  /* -- Move constructor --------------------------------------------------- */
  VarsBase(VarsBase &&vbOther) :
    /* -- Initialisers ----------------------------------------------------- */
    MapType{ vbOther }
    /* -- No code ---------------------------------------------------------- */
    { }
  /* -- Constructor -------------------------------------------------------- */
  VarsBase(void) { }
  /* ----------------------------------------------------------------------- */
  DELETECOPYCTORS(VarsBase);           // Disable copy constructor/operator
}; /* -- A Vars class where the values can be modified --------------------- */
class Vars :
  /* -- Base classes ------------------------------------------------------- */
  public VarsBase<StrNCStrMap>
{ /* --------------------------------------------------------------- */ public:
  void VarsPushOrUpdatePair(const string &strKey, const string &strValue)
  { // Find key and if it exists, just update the value else insert a new one
    const StrNCStrMapIt vIter{ find(strKey) };
    if(vIter != end()) vIter->second = strValue;
    else VarsPushPair(strKey, strValue);
  }
  /* -- Try to move key but copy value ------------------------------------- */
  void VarsPushOrUpdatePair(string &&strKey, const string &strValue)
  { const StrNCStrMapIt vIter{ find(strKey) };
    if(vIter != end()) vIter->second = strValue;
    else VarsPushPair(move(strKey), strValue);
  }
  /* -- Try to move value but copy key ------------------------------------- */
  void VarsPushOrUpdatePair(const string &strKey, string &&strValue)
  { const StrNCStrMapIt vIter{ find(strKey) };
    if(vIter != end()) vIter->second = move(strValue);
    else VarsPushPair(strKey, move(strValue));
  }
  /* -- Try to move key and value ------------------------------------------ */
  void VarsPushOrUpdatePair(string &&strKey, string &&strValue)
  { const StrNCStrMapIt vIter{ find(strKey) };
    if(vIter != end()) vIter->second = move(strValue);
    else VarsPushPair(move(strKey), move(strValue));
  }
  /* ----------------------------------------------------------------------- */
  void VarsPushOrUpdatePairs(const StrPairList &splValues)
  { // Add each value that was sent
    for(const StrPair &spKeyValue : splValues)
      VarsPushOrUpdatePair(move(spKeyValue.first), move(spKeyValue.second));
  }
  /* -- Extracts and deletes the specified key pair ------------------------ */
  const string Extract(const string &strKey)
  { // Find key and return empty string if not found
    const StrNCStrMapIt vIter{ find(strKey) };
    if(vIter == end()) return {};
    // Take ownership of the string (faster than copy)
    const string strOut{ move(vIter->second) };
    // Erase keypair
    erase(vIter);
    // Return the value
    return strOut;
  } /* -- Constructor ------------------------------------------------------ */
  Vars(void) { }
  /* -- MOVE assignment operator ------------------------------------------- */
  Vars& operator=(Vars &&vOther) { swap(vOther); return *this; }
  /* -- MOVE assignment constructor ---------------------------------------- */
  Vars(Vars &&vOther) : VarsBase<StrNCStrMap>{ move(vOther) } { }
  /* -- Constructor -------------------------------------------------------- */
  Vars(const string &strS, const string &strLS, const char cDelimiter) :
    VarsBase<StrNCStrMap>(strS, strLS, cDelimiter) { }
  /* ----------------------------------------------------------------------- */
  DELETECOPYCTORS(Vars);               // Disable copy constructor/operator
};/* ----------------------------------------------------------------------- */
/* -- A Vars class thats values cannot be modified at all ------------------ */
class VarsConst :
  /* -- Base classes ------------------------------------------------------- */
  public VarsBase<StrStrMap>
{ /* -- Constructor ------------------------------------------------ */ public:
  VarsConst(void) { }
  /* -- MOVE assignment operator ------------------------------------------- */
  VarsConst& operator=(VarsConst &&vcOther) { swap(vcOther); return *this; }
  /* -- MOVE assignment constructor ---------------------------------------- */
  VarsConst(VarsConst &&vcOther) : VarsBase<StrStrMap>{ move(vcOther) } { }
  /* -- Constructor -------------------------------------------------------- */
  VarsConst(const string &strS, const string &strLS, const char cDelimiter) :
    /* -- Initialisers ----------------------------------------------------- */
    VarsBase<StrStrMap>{ strS,
      strLS, cDelimiter }
    /* -- No code ---------------------------------------------------------- */
    { }
  /* ----------------------------------------------------------------------- */
  DELETECOPYCTORS(VarsConst);          // Disable copy constructor/operator
};/* -- End of module namespace -------------------------------------------- */
};                                     // End of interface
/* == EoF =========================================================== EoF == */
