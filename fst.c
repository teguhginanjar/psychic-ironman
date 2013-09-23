#include <clutter/clutter.h>


static void 
on_press_key (ClutterActor * rect, gpointer data)
{
    clutter_actor_hide (data);   
}

int 
main (int argc, char ** argv)
{
    if (clutter_init (&argc, &argv) != 
        CLUTTER_INIT_SUCCESS)) 
        return 1;
    ClutterActor * stage  = clutter_actor_new ();
    ClutterActor * rect = clutter_actor_new ();
    clutter_actor_set_size (stage, 400, 400);
    clutter_actor_set_size (rect, 100, 100);
    clutter_actor_set_background_color (stage, CLUTTER_COLOR_Black);
    clutter_actor_set_background_color (rect, CLUTTER_COLOR_Blue);
    clutter_actor_add_child (stage, rect);
    g_signal_connect (stage, "destroy", 
                      G_CALLBACK (clutter_main_quit), NULL);
    g_signal_connect_swapped (rect, "button-press-event", 
                              G_CALLBACK (on_press_key), (gpointer ) rect);
    clutter_actor_set_reactive (rect, TRUE);
    clutter_main ();
    return 0;
}
