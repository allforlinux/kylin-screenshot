// Copyright(c) 2017-2019 Alejandro Sirgo Rica & Contributors
//              2020 KylinSoft Co., Ltd.
// This file is part of Kylin-Screenshot.
//
//     Kylin-Screenshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Kylin-Screenshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Kylin-Screenshot.  If not, see <http://www.gnu.org/licenses/>.

#include "undotool.h"
#include <QPainter>

UndoTool::UndoTool(QObject *parent) : AbstractActionTool(parent) {

}

bool UndoTool::closeOnButtonPressed() const {
    return false;
}

QIcon UndoTool::icon(const QColor &background, bool inEditor) const {
   // Q_UNUSED(inEditor);
    //return QIcon(iconPath(background) + "undo-variant.svg");
    Q_UNUSED(background);
    return inEditor ?  QIcon(QStringLiteral(":/img/material/black/") + "undo-variant.svg") :
                      QIcon(QStringLiteral(":/img/material/white/") + "undo-variant.svg");

}
QString UndoTool::name() const {
    return tr("undo");
}

QString UndoTool::nameID() {
    return QLatin1String("");
}

QString UndoTool::description() const {
    return tr("Undo the last modification");
}

CaptureTool* UndoTool::copy(QObject *parent) {
    return new UndoTool(parent);
}

void UndoTool::pressed(const CaptureContext &context) {
    Q_UNUSED(context);
    emit requestAction(REQ_UNDO_MODIFICATION);
}
