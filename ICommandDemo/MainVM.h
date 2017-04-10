#pragma once

using Windows::UI::Xaml::Data::INotifyPropertyChanged;
using Windows::UI::Xaml::Data::PropertyChangedEventArgs;
using Windows::UI::Xaml::DependencyProperty;
using Windows::UI::Xaml::DependencyObject;
using Windows::UI::Xaml::DependencyPropertyChangedEventArgs;
using Platform::String;

namespace ICommandDemo {

    public ref class MainVM sealed : INotifyPropertyChanged
    {
    public:
        MainVM();

        // Inherited via INotifyPropertyChanged
        virtual event Windows::UI::Xaml::Data::PropertyChangedEventHandler ^ PropertyChanged;

        property Windows::UI::Xaml::Input::ICommand^ ClickCommand {
            Windows::UI::Xaml::Input::ICommand^ get();
        }

        property int Times {
            int get() {
                return _times;
            }

            void set(int value) {
                _times = value;
                OnPropertyChanged("Times");
            }
        }
    private:
        void _Execute(Platform::Object^);
        int _times = 0;

        void OnPropertyChanged(String^ propertyName)
        {
            PropertyChanged(this, ref new PropertyChangedEventArgs(propertyName));
        }
    };
}
