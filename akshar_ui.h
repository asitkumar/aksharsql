
///////////////////////////////////////////
// akshar_ui.h - All UI Elements Go Here //
///////////////////////////////////////////

#ifndef AKSHAR_UI_H
#define AKSHAR_UI_H

#include <gtk/gtk.h>
#include "akshar.h"

void setup_ui() {
	
	// Application Main Window and Alignment
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),AKSHAR_NAME_VER);
	gtk_window_set_resizable(GTK_WINDOW(window),TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window),winWidth,winHeight);
	
	vbox = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show(vbox);
	
	// Application Menu
	fileMenu = gtk_menu_new();
	editMenu = gtk_menu_new();
	toolsMenu = gtk_menu_new();
	helpMenu = gtk_menu_new();
	
	newItem = gtk_menu_item_new_with_label("New");
	openItem = gtk_menu_item_new_with_label("Open");
	saveItem = gtk_menu_item_new_with_label("Save");
	saveAsItem = gtk_menu_item_new_with_label("Save As..");
	exitItem = gtk_menu_item_new_with_label("Exit");
	cutItem = gtk_menu_item_new_with_label("Cut");
	copyItem = gtk_menu_item_new_with_label("Copy");
	pasteItem = gtk_menu_item_new_with_label("Paste");
	fontItem = gtk_menu_item_new_with_label("Font");
	helpMeItem = gtk_menu_item_new_with_label("Help Me!");
	aboutItem = gtk_menu_item_new_with_label("About Akshar..");
	
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),newItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),openItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),saveItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),saveAsItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu),exitItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),cutItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),copyItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),pasteItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(editMenu),fontItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu),helpMeItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu),aboutItem);
	
	fileItem = gtk_menu_item_new_with_label("File");
	editItem = gtk_menu_item_new_with_label("Edit");
	toolsItem = gtk_menu_item_new_with_label("Tools");
	helpItem = gtk_menu_item_new_with_label("Help");
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileItem),fileMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(editItem),editMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(toolsItem),toolsMenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(helpItem),helpMenu);
	
	gtk_widget_show(fileItem);
	gtk_widget_show(editItem);
	gtk_widget_show(toolsItem);
	gtk_widget_show(helpItem);
	
	menuBar = gtk_menu_bar_new();
	
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),fileItem);
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),editItem);
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),toolsItem);
	gtk_menu_bar_append(GTK_MENU_BAR(menuBar),helpItem);
	
	gtk_box_pack_start(GTK_BOX(vbox),menuBar,FALSE,FALSE,0);
	gtk_widget_show(menuBar);
	
	// Display All Widgets
	gtk_widget_show_all(window);
}

#endif

