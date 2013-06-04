#include <clutter/clutter.h>

int 
main (int argc, char ** argv)
{
    if (clutter_init (&argc, &argv) != 
        CLUTTER_INIT_SUCCESS)) 
        return 1;
    
    clutter_main ();
    return 0;
}
