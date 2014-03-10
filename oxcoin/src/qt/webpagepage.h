#ifndef WEBPAGEPAGE_H
#define WEBPAGEPAGE_H

#include <QWidget>
#include <QWebView>

namespace Ui {
    class WebpagePage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class ClientModel;
class WalletModel;

class WebpagePage : public QWidget
{
    Q_OBJECT
public:
    explicit WebpagePage(QWidget *parent = 0);
    ~WebpagePage();
    
signals:
    
public slots:

private:
    Ui::WebpagePage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    QWebView *webView;
    
};

#endif // WEBPAGEPAGE_H
