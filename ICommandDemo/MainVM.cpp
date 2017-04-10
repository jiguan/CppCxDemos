#include "pch.h"
#include "MainVM.h"
#include "DelegateCommand.h"

using namespace ICommandDemo;

using Windows::UI::Xaml::PropertyChangedCallback;
using Windows::UI::Xaml::PropertyMetadata;
using Windows::UI::Xaml::Controls::Primitives::ButtonBase;
using Windows::UI::Xaml::Input::ICommand;

DependencyProperty^ ClickBehavior = nullptr;

MainVM::MainVM() {}

ICommand^ MainVM::ClickCommand::get() {
    return ref new DelegateCommand(ref new ExecuteDelegate(this, &MainVM::_Execute), nullptr);
}

void MainVM::_Execute(Object^) {
    ++Times;
}
