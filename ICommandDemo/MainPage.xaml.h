//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "MainVM.h"

namespace ICommandDemo
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public ref class MainPage sealed
    {
    public:
        MainPage();

        property MainVM^ ViewModel {
            MainVM^ get() {
                return _viewModel;
            }

            void set(MainVM^ value) {
                _viewModel = value;
            }
        }

    private:
        MainVM^ _viewModel;
    };
}
