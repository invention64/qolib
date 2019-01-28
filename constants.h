#ifndef _constants_h
#define _constants_h

//Should common structs be defined in here or in the lib file? 
// In here - Sean
//Also file contains primarily defines

// True False for ez mgmt
#define True 1
#define False 0

//Configurable Definitions
#define SEVERITY 0

//Immutable Definitions
#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define CRITICAL 4

#define max(a,b) \
 ({ __typeof__ (a) _a = (a); \
 __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })
#define min(a,b) \
 ({ __typeof__ (a) _a = (a); \
 __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; })

#endif
