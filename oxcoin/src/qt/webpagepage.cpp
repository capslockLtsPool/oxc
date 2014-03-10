#include "webpagepage.h"
#include "ui_webpagepage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"
#include "guiutil.h"
#include "guiconstants.h"

WebpagePage::WebpagePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebpagePage),
    clientModel(0),
    walletModel(0)
{
    ui->setupUi(this);
    webView = new QWebView(this);
    ui->topLayout->addWidget(webView);
    webView->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    webView->setUrl(QUrl("http://oxcoin.com"));
}

WebpagePage::~WebpagePage()
{
    delete ui;
    delete webView;
}
