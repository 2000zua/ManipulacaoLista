#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>


// Funcao chamada quando o botao e cliacao
void on_button_clicked(GtkWidget* widget, gpointer data){
    g_print("Botao Pressionado!\n");
}

int main(int argc, char* argv[]){
    
    // inicializar o GTK
    gtk_init(&argc, &argv);

    //criar uma janela principal
    GtkWidget* janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(janela), "Tela Principal");
    gtk_container_set_border_width(GTK_CONTAINER(janela), 10);
    gtk_widget_set_size_request(janela, 200,100);

    GtkWidget* button = gtk_button_new_with_label("Cliqu em mim");

    gtk_container_add(GTK_CONTAINER(janela), button);

    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect(janela, "destroy",G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(janela);

    // inicia o loop princpal da gui
    gtk_main();
    return 0;
}



