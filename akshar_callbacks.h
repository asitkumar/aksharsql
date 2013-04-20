
//////////////////////////////////////////////////////////////
// akshar_callbacks.h - All Callbacks Setup and Called Here //
//////////////////////////////////////////////////////////////

#ifndef AKSHAR_CALLBACKS_H
#define AKSHAR_CALLBACKS_H

#include "akshar_ui.h"

// Callback Prototypes //////////////////////////////////////
static gboolean newItemHandler(GtkWidget *, GdkEvent *);
static gboolean openItemHandler(GtkWidget *, GdkEvent *);
static gboolean saveItemHandler(GtkWidget *, GdkEvent *);
static gboolean saveAsItemHandler(GtkWidget *, GdkEvent *);
static gboolean exitItemHandler(GtkWidget *, GdkEvent *);
static gboolean cutItemHandler(GtkWidget *, GdkEvent *);
static gboolean copyItemHandler(GtkWidget *, GdkEvent *);
static gboolean pasteItemHandler(GtkWidget *, GdkEvent *);
static gboolean fontItemHandler(GtkWidget *, GdkEvent *);
static gboolean helpMeItemHandler(GtkWidget *, GdkEvent *);
static gboolean aboutItemHandler(GtkWidget *, GdkEvent *);

void setup_callbacks() {
	
	// Exits the application when X button is clicked
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	// Application menu connect callbacks
	g_signal_connect_swapped(newItem,"activate",G_CALLBACK(newItemHandler),fileMenu);
	g_signal_connect_swapped(openItem,"activate",G_CALLBACK(openItemHandler),fileMenu);
	g_signal_connect_swapped(saveItem,"activate",G_CALLBACK(saveItemHandler),fileMenu);
	g_signal_connect_swapped(saveAsItem,"activate",G_CALLBACK(saveAsItemHandler),fileMenu);
	g_signal_connect_swapped(exitItem,"activate",G_CALLBACK(exitItemHandler),fileMenu);
	g_signal_connect_swapped(cutItem,"activate",G_CALLBACK(cutItemHandler),editMenu);
	g_signal_connect_swapped(copyItem,"activate",G_CALLBACK(copyItemHandler),editMenu);
	g_signal_connect_swapped(pasteItem,"activate",G_CALLBACK(pasteItemHandler),editMenu);
	g_signal_connect_swapped(fontItem,"activate",G_CALLBACK(fontItemHandler),editMenu);
	//g_signal_connect_swapped(Item,"activate",G_CALLBACK(ItemHandler),toolsMenu);
	g_signal_connect_swapped(helpMeItem,"activate",G_CALLBACK(helpMeItemHandler),helpMenu);
	g_signal_connect_swapped(aboutItem,"activate",G_CALLBACK(aboutItemHandler),helpMenu);
}

// Real callbacks //////////////////////////////////////////

static gboolean newItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean openItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean saveItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean saveAsItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean exitItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean cutItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean copyItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean pasteItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean fontItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean helpMeItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean aboutItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}

#endif

