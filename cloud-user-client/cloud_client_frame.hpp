#pragma once

#include <wx/wx.h>
#include <iostream>

namespace cloud_client
{
    namespace gui
    {
        class cloud_client_frame : public wxFrame
        {
        public:
            cloud_client_frame(const wxString& title);
            void on_authorize(wxCommandEvent& event);
            void on_register(wxCommandEvent& event);
            void on_login(wxCommandEvent& event);
            void on_create_account(wxCommandEvent& event);
            void show_busy_info(const wxString& message, const wxString& caption);

        private:
            wxPanel* main_panel;
            wxBoxSizer* main_sizer;
        };
    }
}