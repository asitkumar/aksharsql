
/////////////////////////////////////////////////////////////
// akshar.h - All main declarations go here (Project Base) //
/////////////////////////////////////////////////////////////

#ifndef AKSHAR_H
#define AKSHAR_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define AKSHAR_NAME_VER 		"AksharSQL v1.0"
//#define AKSHAR_MAIN_CONFIG 	"akshar_settings.cfg"

// Main Window and Alignment Widgets
GtkWidget 					*window;
GtkWidget 					*vbox;

// Menu Widgets
GtkWidget 					*menuBar, *menu;
GtkWidget 					*fileMenu, *editMenu, *helpMenu;
GtkWidget 					*fileItem, *editItem, *helpItem;
GtkWidget 					*newItem, *openItem, *saveItem, *saveAsItem, *exitItem; // File Menu
GtkWidget 					*cutItem, *copyItem, *pasteItem, *prefsItem, *runItem, *cancelRunItem; // Edit Menu
GtkWidget 					*helpMeItem, *aboutItem; // Help Menu

// Toolbar Widgets
GtkWidget 					*toolBar;
GtkToolItem 				*tbNew, *tbOpen, *tbSave, *tbSaveAs;
GtkToolItem 				*tbCut, *tbCopy, *tbPaste, *tbPrefs;
GtkToolItem 				*tbRun, *tbCancelRun;

// Sql Editor Widgets
GtkWidget 					*sqlEdit, *scrollWindow;
GtkTextBuffer 			*sqlEditBuffer;
GtkTextIter 				start, end;

// Table
GtkWidget 					*scrollGrid;
GtkListStore 				*store;
GtkTreeIter 				iter;
GtkCellRenderer 		*renderer;
GtkTreeModel        *model;
GtkWidget           *view;
GtkTreeViewColumn   *column;

enum
{
  DEFCOL=0,
  NCOLS
};

// Buffers
gchar 							*edBuffer, *buffer;
char 								*temp;

// Database-related
FILE 								*dbFile;

// Other
int winWidth = 1000;    // Main window width/height
int winHeight = 600;    // Main window width/height

// Miscellaneous
int i, j, k;

#endif

