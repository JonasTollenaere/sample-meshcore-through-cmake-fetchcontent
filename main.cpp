#include <meshcore/utility/FileParser.h>
#include "meshcore/rendering/ApplicationWindow.h"

void run(RenderWidget* renderWidget);

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    ApplicationWindow window;
    window.show();

    std::thread thread(run, window.getRenderWidget());
    int returnCode = QApplication::exec();
    thread.join();
    return returnCode;
}

void run(RenderWidget* renderWidget){

    // Minimal example that renders a banana
    auto modelSpaceMesh = FileParser::loadMeshFile(MESHCORE_DATA_DIR + std::string("E. F. Silva et al. 2021/banana.stl"));
    auto mesh = std::make_shared<WorldSpaceMesh>(modelSpaceMesh);
    renderWidget->renderWorldSpaceMesh("Fruit", mesh, Color::Yellow());
}