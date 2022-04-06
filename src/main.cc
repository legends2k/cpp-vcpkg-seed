#include "main.h"

#include <memory>

#include <spdlog/spdlog.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

void handle_box_click(Fl_Button* button, void* data) {
  spdlog::info("{}: when: {}, value: {}",
    __FILE__, button->when(), +button->value());

  // closing all windows ends the application
  Fl_Window* win = reinterpret_cast<Fl_Window*>(data);
  win->hide();
}

int main(int argc, char** argv) {
  spdlog::info("Hello, world!");
  auto window = std::make_unique<Fl_Window>(340, 180);
  spdlog::info("Window created");
  auto button = new Fl_Button(20, 40, 300, 100, "Hello, World!");
  spdlog::info("Button created");
  button->box(FL_UP_BOX);
  button->labelfont(FL_BOLD + FL_ITALIC);
  button->labelsize(36);
  button->labeltype(FL_SHADOW_LABEL);
  // https://graphics.cs.wisc.edu/WP/cs559-sp2015/2015/02/12/understanding-fltk-callbacks/
  button->when(FL_WHEN_RELEASE | FL_WHEN_CHANGED);
  button->callback(reinterpret_cast<Fl_Callback*>(&handle_box_click), window.get());
  spdlog::info("Window compiled");
  window->end();
  spdlog::info("Window shown");
  window->show(argc, argv);
  spdlog::info("Running the main loop");
  const auto status = Fl::run();
  if (status != 0)
    spdlog::warn("Exiting application with error: {}", status);
  else
    spdlog::info("Exiting application");
  return status;
}
