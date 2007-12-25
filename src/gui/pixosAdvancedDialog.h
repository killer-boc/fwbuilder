/* 

                          Firewall Builder

                 Copyright (C) 2004 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id: pixosAdvancedDialog.h,v 1.1 2004/03/21 03:17:53 vkurland Exp $

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



#ifndef __PIXOSADVANCEDDIALOG_H_
#define __PIXOSADVANCEDDIALOG_H_

#include <ui_pixosadvanceddialog_q.h>
#include "DialogData.h"
#include <QDialog>

namespace libfwbuilder {
    class FWObject;
};

class pixosAdvancedDialog : public QDialog
{
    Q_OBJECT

    libfwbuilder::FWObject *obj;
    DialogData             data;
Ui::pixosAdvancedDialog_q *m_dialog;

 public:
    pixosAdvancedDialog(QWidget *parent,libfwbuilder::FWObject *o);
    ~pixosAdvancedDialog();
    
protected slots:

    virtual void accept();
    virtual void reject();


public slots:

};

#endif // __PIXOSADVANCEDDIALOG_H

