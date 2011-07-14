/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkCheckableComboBox_h
#define __ctkCheckableComboBox_h

// Qt includes
#include <QComboBox>

// CTK includes
#include "ctkWidgetsExport.h"

class ctkCheckableModelHelper;
class ctkCheckableComboBoxPrivate;

/// Description
/// ctkCheckableComboBox is a QComboBox that allow its items to be checkable
class CTK_WIDGETS_EXPORT ctkCheckableComboBox : public QComboBox
{
  Q_OBJECT

public:
  ctkCheckableComboBox(QWidget *parent = 0);
  virtual ~ctkCheckableComboBox();
  
  /// Use setCheckableModel instead of setModel()
  QAbstractItemModel* checkableModel()const;
  void setCheckableModel(QAbstractItemModel *model);
  
  /// Returns an up-to-date list of all the checked indexes.
  QModelIndexList checkedIndexes()const;
  /// Returns true if all the indexes are checked, false otherwise 
  bool allChecked()const;
  /// Returns true if none of the indexes is checked, false otherwise
  bool noneChecked()const;

  /// Utility function to conveniently check the state of an index
  void setCheckState(const QModelIndex& index, Qt::CheckState check);
  /// Utility function to return the check state of a model index
  Qt::CheckState checkState(const QModelIndex& index)const;

  /// Returns a pointer to the checkable model helper to give a direct access
  /// to the check manager.
  ctkCheckableModelHelper* checkableModelHelper()const;
  
  /// Reimplemented for internal reasons
  bool eventFilter(QObject *o, QEvent *e);
  
signals:
  void checkedIndexesChanged();

protected slots:
  void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

protected:
  /// Reimplemented for internal reasons
  virtual void paintEvent(QPaintEvent*);

protected:
  QScopedPointer<ctkCheckableComboBoxPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(ctkCheckableComboBox);
  Q_DISABLE_COPY(ctkCheckableComboBox);
};

#endif
