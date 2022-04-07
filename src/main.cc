#include "main.h"

#include <memory>

#include <spdlog/spdlog.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/names.h>

namespace {

void handle_button_click(Fl_Widget* w, void* data) {
  Fl_Button* button = static_cast<Fl_Button*>(w);

  switch (Fl::event()) {
  case FL_KEYDOWN:
  case FL_RELEASE:
  case FL_SHORTCUT:
  {
    SPDLOG_INFO("{}: Hiding window on event: {}",
      __func__,
      fl_eventnames[Fl::event()]);
    // closing all windows ends the application
    Fl_Window* win = static_cast<Fl_Window*>(data);
    win->hide();
  }
  break;
  default:
    SPDLOG_WARN("{}: {} unhandled", __func__, fl_eventnames[Fl::event()]);
  }
}

}  // namespace

int main(int argc, char** argv) {
  spdlog::info("Hello, world!");
  auto window = std::make_unique<Fl_Window>(340, 180);
  spdlog::info("Window created");
  auto button = new Fl_Button(20, 40, 300, 100, "&Hello, World!");
  spdlog::info("Button created");
  button->box(FL_UP_BOX);
  button->labelfont(FL_BOLD + FL_ITALIC);
  button->labelsize(36);
  button->labeltype(FL_SHADOW_LABEL);
  button->callback(&handle_button_click, window.get());
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
