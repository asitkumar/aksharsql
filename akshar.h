
/////////////////////////////////////////////////////////////
// akshar.h - All main declarations go here (Project Base) //
/////////////////////////////////////////////////////////////

#ifndef AKSHAR_H
#define AKSHAR_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#define AKSHAR_NAME_VER 		"AksharSQL v1.0"
//#define AKSHAR_MAIN_CONFIG 	"akshar_settings.cfg"

// Main Window and Alignment Widgets
GtkWidget *window;
GtkWidget *vbox;

// Menu Widgets
GtkWidget *menuBar, *menu;
GtkWidget *fileMenu, *editMenu, *helpMenu;
GtkWidget *fileItem, *editItem, *helpItem;
GtkWidget *newItem, *openItem, *saveItem, *saveAsItem, *exitItem; // File Menu
GtkWidget *cutItem, *copyItem, *pasteItem, *prefsItem, *runItem, *cancelRunItem; // Edit Menu
GtkWidget *helpMeItem, *aboutItem; // Help Menu

// Toolbar Widgets
GtkWidget *toolBar;
GtkToolItem *tbNew, *tbOpen, *tbSave, *tbSaveAs;
GtkToolItem *tbCut, *tbCopy, *tbPaste, *tbPrefs;
GtkToolItem *tbRun, *tbCancelRun;

// Buffers
gchar *mainBuff;
gchar *dblBuff;

// Other
static int winWidth = 800;     // Main window width/height
static int winHeight = 500;    // Main window width/height

int init_memory() {
	
	mainBuff = (char *) malloc(1000);
	dblBuff = (char *) malloc(1000);
	
	return TRUE;
}

void free_memory() {
	
	free(dblBuff);
	free(mainBuff);
}

#endif

