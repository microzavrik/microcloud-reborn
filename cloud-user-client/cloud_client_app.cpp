#include "cloud_client_app.hpp"
#include "cloud_client_frame.hpp"

namespace cloud_client
{
    namespace gui
    {
        bool cloud_client_app::OnInit()
        {
            cloud_client_frame* frame = new cloud_client_frame("Started MicroCloud-Reborn");
            frame->Show(true);
            return true;
        }
    }
}
