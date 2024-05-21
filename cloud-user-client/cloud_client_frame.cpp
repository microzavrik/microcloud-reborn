
#include "cloud_client_frame.hpp"
#include "interface_colorpsace.h"

namespace cloud_client
{
    namespace gui
    {
        cloud_client_frame::cloud_client_frame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(440, 600))
        {
            SetBackgroundColour(WHITE_BACKGROUND);

            wxPanel* panel = new wxPanel(this, wxID_ANY);
            panel->SetBackgroundColour(WHITE_BACKGROUND); 

            wxButton* authorize_btn = new wxButton(panel, wxID_ANY, "Authorization", wxDefaultPosition, wxSize(195, 40));
            authorize_btn->SetForegroundColour(WHITE_TEXT); 
            authorize_btn->SetBackgroundColour(ORANGE_BACKGROUND); 
            authorize_btn->Bind(wxEVT_BUTTON, &cloud_client_frame::on_authorize, this);

            wxButton* register_btn = new wxButton(panel, wxID_ANY, "Registration", wxDefaultPosition, wxSize(195, 40));
            register_btn->SetForegroundColour(WHITE_TEXT); 
            register_btn->SetBackgroundColour(ORANGE_BACKGROUND);
            register_btn->Bind(wxEVT_BUTTON, &cloud_client_frame::on_register, this);

            main_panel = panel;
            main_sizer = new wxBoxSizer(wxVERTICAL);
            panel->SetSizer(main_sizer);

            wxBoxSizer* button_sizer = new wxBoxSizer(wxHORIZONTAL);
            button_sizer->Add(authorize_btn, 0, wxALIGN_CENTER | wxRIGHT, 10);
            button_sizer->Add(register_btn, 0, wxALIGN_CENTER | wxLEFT, 10);
            main_sizer->Add(button_sizer, 0, wxALIGN_CENTER | wxTOP, 20);
        }

        void cloud_client_frame::on_authorize(wxCommandEvent& event)
        {
            main_panel->DestroyChildren();
            wxStaticText* username_label = new wxStaticText(main_panel, wxID_ANY, "Username:");
            username_label->SetForegroundColour(BLACK_TEXT); 
            wxTextCtrl* username_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30));
            username_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND);
            username_field->SetForegroundColour(BLACK_TEXT);
            wxStaticText* password_label = new wxStaticText(main_panel, wxID_ANY, "Password:");
            password_label->SetForegroundColour(BLACK_TEXT);
            wxTextCtrl* password_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30), wxTE_PASSWORD);
            password_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND);
            password_field->SetForegroundColour(BLACK_TEXT);
            main_sizer->Add(username_label, 0, wxALIGN_CENTER | wxTOP, 10);
            main_sizer->Add(username_field, 0, wxALIGN_CENTER | wxTOP, 5);
            main_sizer->Add(password_label, 0, wxALIGN_CENTER | wxTOP, 10);
            main_sizer->Add(password_field, 0, wxALIGN_CENTER | wxTOP, 5);

            wxButton* login_btn = new wxButton(main_panel, wxID_ANY, "Login", wxDefaultPosition, wxSize(130, 40));
            login_btn->SetForegroundColour(WHITE_TEXT);
            login_btn->SetBackgroundColour(ORANGE_BACKGROUND); 
            login_btn->Bind(wxEVT_BUTTON, &cloud_client_frame::on_login, this);
            main_sizer->Add(login_btn, 0, wxALIGN_CENTER | wxTOP, 10);

            main_panel->Layout();
        }

        void cloud_client_frame::on_register(wxCommandEvent& event)
        {
            main_panel->DestroyChildren();
            wxStaticText* username_label = new wxStaticText(main_panel, wxID_ANY, "Username:");
            username_label->SetForegroundColour(BLACK_TEXT);
            wxTextCtrl* username_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30));
            username_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND); 
            username_field->SetForegroundColour(BLACK_TEXT);
            wxStaticText* password_label = new wxStaticText(main_panel, wxID_ANY, "Password:");
            password_label->SetForegroundColour(BLACK_TEXT);
            wxTextCtrl* password_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30), wxTE_PASSWORD);
            password_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND);
            password_field->SetForegroundColour(BLACK_TEXT); 
            wxStaticText* confirm_label = new wxStaticText(main_panel, wxID_ANY, "Confirm Password:");
            confirm_label->SetForegroundColour(BLACK_TEXT); 
            wxTextCtrl* confirm_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30), wxTE_PASSWORD);
            confirm_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND); 
            confirm_field->SetForegroundColour(BLACK_TEXT); 
            main_sizer->Add(username_label, 0, wxALIGN_CENTER | wxTOP, 10);
            main_sizer->Add(username_field, 0, wxALIGN_CENTER | wxTOP, 5);
            main_sizer->Add(password_label, 0, wxALIGN_CENTER | wxTOP, 10);
            main_sizer->Add(password_field, 0, wxALIGN_CENTER | wxTOP, 5);
            main_sizer->Add(confirm_label, 0, wxALIGN_CENTER | wxTOP, 10);
            main_sizer->Add(confirm_field, 0, wxALIGN_CENTER | wxTOP, 5);

            wxButton* create_account_btn = new wxButton(main_panel, wxID_ANY, "Create Account", wxDefaultPosition, wxSize(195, 40));
            create_account_btn->SetForegroundColour(WHITE_TEXT);
            create_account_btn->SetBackgroundColour(ORANGE_BACKGROUND);
            create_account_btn->Bind(wxEVT_BUTTON, &cloud_client_frame::on_create_account, this);
            main_sizer->Add(create_account_btn, 0, wxALIGN_CENTER | wxTOP, 10);

            main_panel->Layout();
        }

        void cloud_client_frame::on_create_account(wxCommandEvent& event)
        {
            wxTextCtrl* username_field = wxDynamicCast(main_panel->GetChildren().Item(1)->GetData(), wxTextCtrl);
            wxTextCtrl* password_field = wxDynamicCast(main_panel->GetChildren().Item(3)->GetData(), wxTextCtrl);
            wxTextCtrl* confirm_field = wxDynamicCast(main_panel->GetChildren().Item(5)->GetData(), wxTextCtrl);
            std::cout << "Account Creation Information:" << std::endl;
            std::cout << "Username: " << username_field->GetValue().ToStdString() << std::endl;
            std::cout << "Password: " << password_field->GetValue().ToStdString() << std::endl;
            std::cout << "Confirm Password: " << confirm_field->GetValue().ToStdString() << std::endl;

            main_panel->DestroyChildren();
            wxStaticText* code_label = new wxStaticText(main_panel, wxID_ANY, "Code to connect to you: OFIC4");
            code_label->SetForegroundColour(BLACK_TEXT);
            wxStaticText* input_label = new wxStaticText(main_panel, wxID_ANY, "Enter local cloud code");
            input_label->SetForegroundColour(BLACK_TEXT);
            wxTextCtrl* code_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30));
            code_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND);
            code_field->SetForegroundColour(BLACK_TEXT);
            wxButton* connect_btn = new wxButton(main_panel, wxID_ANY, "Connect", wxDefaultPosition, wxSize(130, 40));
            connect_btn->SetForegroundColour(WHITE_TEXT);
            connect_btn->SetBackgroundColour(ORANGE_BACKGROUND);
            main_sizer->Add(code_label, 0, wxALIGN_CENTER | wxTOP, 20);
            main_sizer->Add(input_label, 0, wxALIGN_CENTER | wxTOP, 13);
            main_sizer->Add(code_field, 0, wxALIGN_CENTER | wxTOP, 5);
            main_sizer->Add(connect_btn, 0, wxALIGN_CENTER | wxTOP, 10);
            
            wxScrolledWindow* scrolled_window = new wxScrolledWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
            wxBoxSizer* scrolled_sizer = new wxBoxSizer(wxVERTICAL);
            scrolled_window->SetSizer(scrolled_sizer);

            for (int i = 1; i <= 20; i++) {
                wxString element_text = wxString::Format("Element %d", i);

                // Create a horizontal box sizer for each item
                wxBoxSizer* item_sizer = new wxBoxSizer(wxHORIZONTAL);

                // Add text to the item
                wxStaticText* text = new wxStaticText(scrolled_window, wxID_ANY, element_text);
                item_sizer->Add(text, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

                wxButton* download_btn = new wxButton(scrolled_window, wxID_ANY, "Download");
                download_btn->SetForegroundColour(WHITE_TEXT);
                download_btn->SetBackgroundColour(ORANGE_BACKGROUND);
                item_sizer->Add(download_btn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

                download_btn->Bind(wxEVT_BUTTON, [this, i](wxCommandEvent& event) {
                    std::cout << "Download button pressed for item " << i << std::endl;
                    });

                scrolled_sizer->Add(item_sizer, 0, wxEXPAND | wxALL, 5);
            }

            scrolled_window->SetScrollRate(0, 10); 
            scrolled_window->FitInside();

            main_sizer->Add(scrolled_window, 1, wxEXPAND | wxALL, 10); 

            main_panel->Layout();
        }

        void cloud_client_frame::on_login(wxCommandEvent& event)
        {
            wxTextCtrl* username_field = wxDynamicCast(main_panel->GetChildren().Item(1)->GetData(), wxTextCtrl);
            wxTextCtrl* password_field = wxDynamicCast(main_panel->GetChildren().Item(3)->GetData(), wxTextCtrl);
            std::cout << "Login Information:" << std::endl;
            std::cout << "Username: " << username_field->GetValue().ToStdString() << std::endl;
            std::cout << "Password: " << password_field->GetValue().ToStdString() << std::endl;

            main_panel->DestroyChildren();
            wxStaticText* code_label = new wxStaticText(main_panel, wxID_ANY, "Code to connect to you: OFIC4");
            code_label->SetForegroundColour(BLACK_TEXT);
            wxStaticText* input_label = new wxStaticText(main_panel, wxID_ANY, "Enter local cloud code");
            input_label->SetForegroundColour(BLACK_TEXT);
            wxTextCtrl* code_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxSize(260, 30));
            code_field->SetBackgroundColour(LIGHT_GRAY_BACKGROUND);
            code_field->SetForegroundColour(BLACK_TEXT);
            wxButton* connect_btn = new wxButton(main_panel, wxID_ANY, "Connect", wxDefaultPosition, wxSize(130, 40));
            connect_btn->SetForegroundColour(WHITE_TEXT);
            connect_btn->SetBackgroundColour(ORANGE_BACKGROUND);
            main_sizer->Add(code_label, 0, wxALIGN_CENTER | wxTOP, 20);
            main_sizer->Add(input_label, 0, wxALIGN_CENTER | wxTOP, 13);
            main_sizer->Add(code_field, 0, wxALIGN_CENTER | wxTOP, 5);
            main_sizer->Add(connect_btn, 0, wxALIGN_CENTER | wxTOP, 10);
            
            wxScrolledWindow* scrolled_window = new wxScrolledWindow(main_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
            wxBoxSizer* scrolled_sizer = new wxBoxSizer(wxVERTICAL);
            scrolled_window->SetSizer(scrolled_sizer);

            for (int i = 1; i <= 20; i++) {
                wxString element_text = wxString::Format("Element %d", i);

                wxBoxSizer* item_sizer = new wxBoxSizer(wxHORIZONTAL);

                wxStaticText* text = new wxStaticText(scrolled_window, wxID_ANY, element_text);
                item_sizer->Add(text, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

                wxButton* download_btn = new wxButton(scrolled_window, wxID_ANY, "Download");
                download_btn->SetForegroundColour(WHITE_TEXT);
                download_btn->SetBackgroundColour(ORANGE_BACKGROUND);
                item_sizer->Add(download_btn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

                download_btn->Bind(wxEVT_BUTTON, [this, i](wxCommandEvent& event) {
                    std::cout << "Download button pressed for item " << i << std::endl;
                    });

                scrolled_sizer->Add(item_sizer, 0, wxEXPAND | wxALL, 5);
            }

            scrolled_window->SetScrollRate(0, 10); 
            scrolled_window->FitInside();

            main_sizer->Add(scrolled_window, 1, wxEXPAND | wxALL, 10); 

            main_panel->Layout();
        }

        void cloud_client_frame::show_busy_info(const wxString& message, const wxString& caption)
        {
            wxMessageBox(message, caption);
        }
    }
}