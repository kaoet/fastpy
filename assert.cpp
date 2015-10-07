#include <cstdio>
#include <cstdlib>
#include <execinfo.h>

void my_assert(bool value, const char *code) {
    if (value) return;
    fprintf(stderr, "Assertion %s failed\n", code);
 
    // storage array for stack trace address data
    void* addrlist[64];
 
    // retrieve current stack addresses
    unsigned addrlen = backtrace(addrlist, sizeof( addrlist ) / sizeof( void* ));
 
    if ( addrlen == 0 ) 
    {
       fprintf(stderr, "  \n" );
       return;
    }
 
    // create readable strings to each frame.
    char** symbollist = backtrace_symbols( addrlist, addrlen );
 
    // print the stack trace.
    for (unsigned i = 4; i < addrlen; i++ )
       fprintf(stderr, "%s\n", symbollist[i]);
 
    free(symbollist);
    abort();
}