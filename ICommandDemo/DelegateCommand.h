#pragma once
using Windows::UI::Xaml::Input::ICommand;
using Windows::Foundation::EventHandler;
using Windows::Foundation::Metadata::WebHostHiddenAttribute;

namespace ICommandDemo {
    public delegate void ExecuteDelegate(Platform::Object^ parameter);
    public delegate bool CanExecuteDelegate(Platform::Object^ parameter);

    [WebHostHidden]
    public ref class DelegateCommand sealed : public ICommand
    {
    public:
        DelegateCommand(void);
        DelegateCommand(ExecuteDelegate^ execute, CanExecuteDelegate^ canExecute);

        void RaiseCanExecuteChanged();

        // Inherited via ICommand
        virtual event Windows::Foundation::EventHandler<Platform::Object ^> ^ CanExecuteChanged;
        virtual bool CanExecute(Platform::Object ^parameter);
        virtual void Execute(Platform::Object ^parameter);

    private:
        ExecuteDelegate^ m_executeDelegate;
        CanExecuteDelegate^ m_canExecuteDelegate;
        bool m_canExecute;
    };

}
