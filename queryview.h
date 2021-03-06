/*
  LICENSE AND COPYRIGHT INFORMATION - Please read carefully.

  Copyright (c) 2011-2012, davyjones <davyjones@github>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef QUERYVIEW_H
#define QUERYVIEW_H

#include <QSqlTableModel>
#include <QSqlError>
#include <QtGui>
#include <QObject>
#include "pgxconsole.h"
#include "querymodel.h"

class QueryView : public QMainWindow
{
    Q_OBJECT

private:
    QString time_elapsed_string;
    QString rows_string;
    QString colums_string;
    QString seconds_string;

    Database *database;
    QMenu *fileMenu;
    QTime t;
    double time_elapsed;
    QTableView *query_view;
    QueryModel *query_model;
    QToolBar *toolbar;
    QStandardItemModel *errors_model;
    QShortcut *shortcut_fullscreen;
    QShortcut *shortcut_restore;
    QString sql;
    QStringList whereCl;
    QStringList orderCl;
    ulong thisQueryViewId;
    QAction *copy_action;
    QAction *copy_with_headers_action;
    QAction *scatterplot_action;
    QAction *lineplot_action;
    QAction *barplot_action;
    QAction *areaplot_action;
    bool thread_busy;

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *);
    void closeEvent(QCloseEvent *);

public:
    static ulong queryViewObjectId;
    QueryView(Database *, QString);
    ~QueryView(){}
    void createActions();

    ulong getId()
    {
        return this->thisQueryViewId;
    }
    QString query()
    {
        return sql;
    }
    void notBusy();
    void enableCopyActions();
    void disableCopyActions();

public slots:
    void bringOnTop();
    void togglePlots();
    void languageChanged(QEvent*);

private slots:
    void copyToClipboard();
    void copyToClipboardWithHeaders();
    void busySlot();
    void updRowCntSlot(QString);
    void fullscreen();
    void restore();
    void fetchData(QString);
    void scatterPlot();
    void linePlot();
    void barPlot();
    void areaPlot();

signals:
    void busySignal();
    void updRowCntSignal(QString);
    void errMesg(QString, uint);
    void queryViewClosing(QueryView*);
};

#endif // QUERYVIEW_H
