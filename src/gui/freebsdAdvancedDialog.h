/* 

                          Firewall Builder

                 Copyright (C) 2004 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id: freebsdAdvancedDialog.h,v 1.1 2004/05/11 04:45:38 vkurland Exp $

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


#ifndef __FREEBSDADVANCEDDIALOG_H_
#define __FREEBSDADVANCEDDIALOG_H_

#include <ui_freebsdadvanceddialog_q.h>
#include "DialogData.h"
#include <QDialog>

namespace libfwbuilder {
    class FWObject;
};

class freebsdAdvancedDialog : public QDialog
{
    Q_OBJECT

    libfwbuilder::FWObject *obj;
    DialogData                       data;
    Ui::freebsdAdvancedDialog_q     *m_dialog;

 public:
    freebsdAdvancedDialog(QWidget *parent,libfwbuilder::FWObject *o);
    ~freebsdAdvancedDialog();
    
protected slots:

    virtual void accept();
    virtual void reject();


};

#endif // __FREEBSDADVANCEDDIALOG_H

