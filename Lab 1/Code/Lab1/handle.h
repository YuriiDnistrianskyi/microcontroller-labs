#ifndef HANDLE_H
#define HANDLE_H

#include "html.h"

extern void setInterval();
extern WebServer server;


void handleRoot() {
    server.send(200, "text/html", html);
  }

  
void handleWebClick() {
  setInterval();
  server.send(200, "text/html", "Click");
}


#endif // HANDLE_H
