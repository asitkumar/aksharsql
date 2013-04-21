
#ifndef AKSHAR_UTILS_H
#define AKSHAR_UTILS_H

#include "akshar.h"

void msgbox(const char *msg) {
	GtkWidget *dialog = gtk_message_dialog_new (GTK_WINDOW(window),
                                  GTK_DIALOG_DESTROY_WITH_PARENT,
                                  GTK_MESSAGE_INFO,
                                  GTK_BUTTONS_CLOSE,
                                  msg);
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

#endif

