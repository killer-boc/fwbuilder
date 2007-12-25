/* 

                          Firewall Builder

                 Copyright (C) 2003 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@fwbuilder.org

  $Id: ObjectIconViewItem.h,v 1.4 2005/09/07 16:40:50 vkurland Exp $

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



#ifndef  __OBJECTICONVIEWITEM_H
#define  __OBJECTICONVIEWITEM_H

#include <qlistwidget.h>

#include <qstring.h>
#include <string>
#include <qmap.h>

namespace libfwbuilder {
    class FWObject;
}

class ObjectIconViewItem : public QListWidgetItem {

    libfwbuilder::FWObject  *objptr;
    QMap<QString, QString>   props;
    std::string                 ID;  
    
 public:

    ObjectIconViewItem(QListWidget *parent) : QListWidgetItem(parent) {
        objptr=NULL;
//        setDropEnabled(false);
        ID="";
    }

    ObjectIconViewItem(QListWidget *parent, const QString &text, const QPixmap &icon ) : QListWidgetItem(parent) 
    {
        objptr=NULL;
        setText(text);
        setIcon(QIcon(icon));
//        setDropEnabled(false);
        ID="";
    }

    libfwbuilder::FWObject *getFWObject() { return mw->db()->getById(ID,true); }
    std::string getFWObjectID() {return ID; }
    void setFWObject(libfwbuilder::FWObject *obj) {ID=obj->getId(); }

    QString getProperty(const QString &name) { return props[name]; }
    void    setProperty(const QString &name,const QString &val) {
        props[name]=val;
    }
};

#endif
