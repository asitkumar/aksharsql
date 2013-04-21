
//////////////////////////////////////////////////////////////
// akshar_callbacks.h - All Callbacks Setup and Called Here //
//////////////////////////////////////////////////////////////

#ifndef AKSHAR_CALLBACKS_H
#define AKSHAR_CALLBACKS_H

#include "akshar_ui.h"
#include "akshar_utils.h"

// Callback Prototypes //////////////////////////////////////
static gboolean newItemHandler(GtkWidget *, GdkEvent *);
static gboolean openItemHandler(GtkWidget *, GdkEvent *);
static gboolean saveItemHandler(GtkWidget *, GdkEvent *);
static gboolean saveAsItemHandler(GtkWidget *, GdkEvent *);
static gboolean exitItemHandler(GtkWidget *, GdkEvent *);
static gboolean cutItemHandler(GtkWidget *, GdkEvent *);
static gboolean copyItemHandler(GtkWidget *, GdkEvent *);
static gboolean pasteItemHandler(GtkWidget *, GdkEvent *);
static gboolean prefsItemHandler(GtkWidget *, GdkEvent *);
static gboolean runItemHandler(GtkWidget *, GdkEvent *);
static gboolean cancelRunItemHandler(GtkWidget *, GdkEvent *);
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
	g_signal_connect(exitItem,"activate",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect_swapped(cutItem,"activate",G_CALLBACK(cutItemHandler),editMenu);
	g_signal_connect_swapped(copyItem,"activate",G_CALLBACK(copyItemHandler),editMenu);
	g_signal_connect_swapped(pasteItem,"activate",G_CALLBACK(pasteItemHandler),editMenu);
	g_signal_connect_swapped(prefsItem,"activate",G_CALLBACK(prefsItemHandler),editMenu);
	g_signal_connect_swapped(runItem,"activate",G_CALLBACK(runItemHandler),editMenu);
	g_signal_connect_swapped(cancelRunItem,"activate",G_CALLBACK(cancelRunItemHandler),editMenu);
	g_signal_connect_swapped(helpMeItem,"activate",G_CALLBACK(helpMeItemHandler),helpMenu);
	g_signal_connect_swapped(aboutItem,"activate",G_CALLBACK(aboutItemHandler),helpMenu);
	
	// Application toolbar connect callbacks
	g_signal_connect(G_OBJECT(tbNew), "clicked", G_CALLBACK(newItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbOpen), "clicked", G_CALLBACK(openItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbSave), "clicked", G_CALLBACK(saveItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbSaveAs), "clicked", G_CALLBACK(saveAsItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbCut), "clicked", G_CALLBACK(cutItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbCopy), "clicked", G_CALLBACK(copyItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbPaste), "clicked", G_CALLBACK(pasteItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbPrefs), "clicked", G_CALLBACK(prefsItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbRun), "clicked", G_CALLBACK(runItemHandler), NULL);
	g_signal_connect(G_OBJECT(tbCancelRun), "clicked", G_CALLBACK(cancelRunItemHandler), NULL);
}

// Real callbacks //////////////////////////////////////////

static gboolean newItemHandler(GtkWidget *widget,GdkEvent *event) {

	msgbox("sup? :D");
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
static gboolean cutItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean copyItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean pasteItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean prefsItemHandler(GtkWidget *widget,GdkEvent *event) {
	
	msgbox("DEBUG: You clicked Preference!");
	return TRUE;
}
static gboolean runItemHandler(GtkWidget *widget,GdkEvent *event) {
	
	msgbox("DEBUG: You clicked Execute!");
	return TRUE;
}
static gboolean cancelRunItemHandler(GtkWidget *widget,GdkEvent *event) {
	
	msgbox("DEBUG: You clicked Cancel Execute!");
	return TRUE;
}
static gboolean helpMeItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}
static gboolean aboutItemHandler(GtkWidget *widget,GdkEvent *event) {
	return TRUE;
}

#endif

