#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include

class Window: public QMainWindow
{
    Q_OBJECT

    public:
        virtual ~Window() = default;
        virtual void updateProductTable() = 0;
    protected:
        Window() = default;
};

#endif // WINDOW_H
