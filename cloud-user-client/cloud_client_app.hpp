#pragma once

#include "cloud_client_frame.hpp"

namespace cloud_client
{
    namespace gui
    {
        class cloud_client_app : public wxApp
        {
        public:
            virtual bool OnInit();
        };
    }
}