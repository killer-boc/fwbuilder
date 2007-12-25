/*

                          Firewall Builder

                 Copyright (C) 2004 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id: newHostDialog.h,v 1.5 2006/06/16 04:33:13 vkurland Exp $

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#ifndef __NEWHOSTDIALOG_H_
#define __NEWHOSTDIALOG_H_

#include "../../config.h"
#include <ui_newhostdialog_q.h>

#include "InterfaceData.h"
#include "fakeWizard.h"
#include <QDialog>

#include <map>

namespace libfwbuilder {
    class FWObject;
    class Host;
    class Interface;
    class Logger;
    class SNMP_interface_query;
};

class QTimer;
class QTextEdit;
class QTreeWidgetItem;
class QListWidgetItem;

class newHostDialog : public QDialog, public FakeWizard
{
    Q_OBJECT

    libfwbuilder::Host                 *nhst;
    bool                                snmpPollCompleted;
    libfwbuilder::Logger               *logger;
    libfwbuilder::SNMP_interface_query *q;
    QTimer                             *timer;
    libfwbuilder::FWObjectDatabase     *tmpldb;
    std::map<QListWidgetItem*, libfwbuilder::FWObject*> templates;
    bool                                unloadTemplatesLib;
    bool                                getInterfacesBusy;
    Ui::newHostDialog_q                *m_dialog;


    void fillInterfaceData(libfwbuilder::Interface *intf, QTextBrowser *qte);

 public:
    newHostDialog();
    virtual ~newHostDialog();

    libfwbuilder::Host* getNewHost() { return nhst; };

    virtual bool appropriate(const int page) const;
    void showPage(const int page);

public slots:
    virtual void addInterface();
    virtual void updateInterface();
    virtual void deleteInterface();
    virtual void changed();
    virtual void selectedInterface(QTreeWidgetItem *cur);
    virtual void getInterfacesViaSNMP();    
    virtual void monitor();
    virtual void templateSelected(QListWidgetItem *cur);
    
 protected slots:
    virtual void finishClicked();
    virtual void cancelClicked();
    virtual void nextClicked();
    virtual void backClicked();
 
};

#endif // __NEWHOSTDIALOG_H
