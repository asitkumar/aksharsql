
//////////////////////////////////////////////////////////////
// akshar_callbacks.h - All Callbacks Setup and Called Here //
//////////////////////////////////////////////////////////////

#ifndef AKSHAR_CALLBACKS_H
#define AKSHAR_CALLBACKS_H

#include <gtk/gtk.h>
#include "akshar_ui.h"

void setup_callbacks() {
	
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
}

#endif

