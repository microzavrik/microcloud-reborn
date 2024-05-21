#include "cloud_client_app.hpp"

wxIMPLEMENT_APP(cloud_client::gui::cloud_client_app);

int main(int argc, char* argv[])
{
    wxApp::SetInstance(new cloud_client::gui::cloud_client_app());
    wxEntryStart(argc, argv);
    wxTheApp->OnInit();
    wxTheApp->OnRun();
    wxTheApp->OnExit();
    wxEntryCleanup();
    return 0;
}