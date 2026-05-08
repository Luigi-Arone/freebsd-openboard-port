/*
 * Copyright (C) 2015-2022 Département de l'Instruction Publique (DIP-SEM)
 *
 * Copyright (C) 2013 Open Education Foundation
 *
 * Copyright (C) 2010-2013 Groupement d'Intérêt Public pour
 * l'Education Numérique en Afrique (GIP ENA)
 *
 * This file is part of OpenBoard.
 *
 * OpenBoard is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * OpenBoard is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenBoard. If not, see <http://www.gnu.org/licenses/>.
 */


#include "UBPlatformUtils.h"

#include <QtGui>
#include <QApplication>
#include <QProcessEnvironment>
#include <unistd.h>
#include <X11/keysym.h>

#include "frameworks/UBFileSystemUtils.h"
#include "core/UBApplication.h"
#include "core/UBDisplayManager.h"
#include "core/UBSettings.h"
#include "gui/UBMainWindow.h"

void UBPlatformUtils::init()
{
    initializeKeyboardLayouts();
}

// stringification macros
#define xstr(s) str(s)
#define str(x) #x

// base relocation for testing
#ifdef NDEBUG
#define OPENBOARD_BASE QString()
#else
#define OPENBOARD_BASE QProcessEnvironment::systemEnvironment().value("OPENBOARD_BASE", "")
#endif

QString UBPlatformUtils::applicationResourcesDirectory()
{
#ifdef OPENBOARD_FHS_LAYOUT
    QString prefix = OPENBOARD_BASE + xstr(OPENBOARD_APP_PREFIX);
    return QFileInfo(prefix).absoluteFilePath();
#else
    return QApplication::applicationDirPath();
#endif
}

QString UBPlatformUtils::applicationEtcDirectory()
{
#ifdef OPENBOARD_FHS_LAYOUT
    QString prefix = OPENBOARD_BASE + xstr(OPENBOARD_ETC_PREFIX);
    return QFileInfo(prefix).absoluteFilePath();
#else
    return applicationResourcesDirectory() + "/etc";
#endif
}

QString UBPlatformUtils::applicationTemplateDirectory()
{
#ifdef OPENBOARD_FHS_LAYOUT
    QString prefix = OPENBOARD_BASE + xstr(OPENBOARD_TPL_PREFIX);
    return QFileInfo(prefix).absoluteFilePath();
#else
    return applicationResourcesDirectory() + "/etc";
#endif
}

void UBPlatformUtils::hideFile(const QString &filePath)
{
    Q_UNUSED(filePath)
}

void UBPlatformUtils::setFileType(const QString &filePath, unsigned long fileType)
{
    Q_UNUSED(filePath)
    Q_UNUSED(fileType)
}

void UBPlatformUtils::fadeDisplayOut()
{
    // NOOP
}

void UBPlatformUtils::fadeDisplayIn()
{
    // NOOP
}

bool UBPlatformUtils::hasSystemOnScreenKeyboard()
{
    return false;
}

QStringList UBPlatformUtils::availableTranslations()
{
    QString translationsPath = applicationResourcesDirectory() + "/" + "i18n" + "/";
    QStringList translationsList = UBFileSystemUtils::allFiles(translationsPath);
    static const QRegularExpression sankoreTranslationFiles("(.*)OpenBoard_(.*).qm");
    translationsList = translationsList.filter(sankoreTranslationFiles);
    return translationsList.replaceInStrings(sankoreTranslationFiles, "\\2");
}

QString UBPlatformUtils::translationPath(QString pFilePrefix, QString pLanguage)
{
    QString qmPath = applicationResourcesDirectory() + "/" + "i18n" + "/" + pFilePrefix + pLanguage + ".qm";
    return qmPath;
}

QString UBPlatformUtils::systemLanguage()
{
    return QLocale::system().name();
}

void UBPlatformUtils::bringPreviousProcessToFront()
{
    // Not applicable on FreeBSD
}

QString UBPlatformUtils::osUserLoginName()
{
    char *user = getenv("USER");
    return QString::fromLatin1(user);
}

QString UBPlatformUtils::computerName()
{
    char hostname[256];
    memset(hostname, 0, 256);
    if (!gethostname(hostname, 255))
        return QString::fromLatin1(hostname);
    else
        return "NOT FOUND";
}

void UBPlatformUtils::setWindowNonActivableFlag(QWidget* widget, bool nonActivable)
{
    Q_UNUSED(widget);
    Q_UNUSED(nonActivable);
}

void UBPlatformUtils::hideMenuBarAndDock()
{
    // NOOP
}

#define KEYBTDECL(s1, s2, clSwitch, code) KEYBT(QChar(s1), QChar(s2), clSwitch, 0, 0, KEYCODE(s1, code, 0), KEYCODE(s2, code, 1))
#define KEYBTDECLEX1(s1, s2, clSwitch, code, cs1, cs2) KEYBT(QChar(s1), QChar(s2), clSwitch, 0, 0, KEYCODE(cs1, code, 0), KEYCODE(cs2, code, 1))
#define KEYBTDECLEX2(s1, s2, clSwitch, code, cs1, cs2) KEYBT(QChar(s1), QChar(s2), clSwitch, 0, 0, KEYCODE(cs1, code, 2), KEYCODE(cs2, code, 3))
#define KEYBTDECLEX6(s1, s2, clSwitch, code, cs1, cs2, cs3, cs4, cs5, cs6) KEYBT(QChar(s1), QChar(s2), clSwitch, 0, 0, KEYCODE(cs1, code, 0), KEYCODE(cs2, code, 1), KEYCODE(cs3, code, 2), KEYCODE(cs4, code, 3), KEYCODE(cs5, code, 4), KEYCODE(cs6, code, 5))
#define KEYBTDECLEX8(s1, s2, clSwitch, code, cs1, cs2, cs3, cs4, cs5, cs6, cs7, cs8) KEYBT(QChar(s1), QChar(s2), clSwitch, 0, 0, KEYCODE(cs1, code, 0), KEYCODE(cs2, code, 1), KEYCODE(cs3, code, 2), KEYCODE(cs4, code, 3), KEYCODE(cs5, code, 4), KEYCODE(cs6, code, 5), KEYCODE(cs7, code, 6), KEYCODE(cs8, code, 7))

KEYBT ENGLISH_LOCALE[] = {
    /* ` ~ */ KEYBTDECL(0x60, 0x7e, false, 41),
    /* 1 ! */ KEYBTDECL(0x31, 0x21, false, 2),
    /* 2 @ */ KEYBTDECL(0x32, 0x40, false, 3),
    /* 3 # */ KEYBTDECL(0x33, 0x23, false, 4),
    /* 4 $ */ KEYBTDECL(0x34, 0x24, false, 5),
    /* 5 % */ KEYBTDECL(0x35, 0x25, false, 6),
    /* 6 ^ */ KEYBTDECL(0x36, 0x88, false, 7),
    /* 7 & */ KEYBTDECL(0x37, 0x26, false, 8),
    /* 8 * */ KEYBTDECL(0x38, 0x2a, false, 9),
    /* 9 ( */ KEYBTDECL(0x39, 0x28, false, 10),
    /* 0 ) */ KEYBTDECL(0x30, 0x29, false, 11),
    /* - _ */ KEYBTDECL(0x2d, 0x5f, false, 12),
    /* = + */ KEYBTDECL(0x3d, 0x2b, false, 13),
    /* q Q */ KEYBTDECL(0x71, 0x51, true, 16),
    /* w W */ KEYBTDECL(0x77, 0x57, true, 17),
    /* e E */ KEYBTDECL(0x65, 0x45, true, 18),
    /* r R */ KEYBTDECL(0x72, 0x52, true, 19),
    /* t T */ KEYBTDECL(0x74, 0x54, true, 20),
    /* y Y */ KEYBTDECL(0x79, 0x59, true, 21),
    /* u U */ KEYBTDECL(0x75, 0x55, true, 22),
    /* i I */ KEYBTDECL(0x69, 0x49, true, 23),
    /* o O */ KEYBTDECL(0x6f, 0x4f, true, 24),
    /* p P */ KEYBTDECL(0x70, 0x50, true, 25),
    /* [ { */ KEYBTDECL(0x5b, 0x7b, false, 26),
    /* ] } */ KEYBTDECL(0x5d, 0x7d, false, 27),
    /* a A */ KEYBTDECL(0x61, 0x41, true, 30),
    /* s S */ KEYBTDECL(0x73, 0x53, true, 31),
    /* d D */ KEYBTDECL(0x64, 0x44, true, 32),
    /* f F */ KEYBTDECL(0x66, 0x46, true, 33),
    /* g G */ KEYBTDECL(0x67, 0x47, true, 34),
    /* h H */ KEYBTDECL(0x68, 0x48, true, 35),
    /* j J */ KEYBTDECL(0x6a, 0x4a, true, 36),
    /* k K */ KEYBTDECL(0x6b, 0x4b, true, 37),
    /* l L */ KEYBTDECL(0x6c, 0x4c, true, 38),
    /* ; : */ KEYBTDECL(0x3b, 0x3a, false, 39),
    /* ' " */ KEYBTDECL(0x27, 0x22, false, 40),
    /* \ | */ KEYBTDECL(0x5c, 0x7c, false, 43),
    /* z Z */ KEYBTDECL(0x7a, 0x5a, true, 44),
    /* x X */ KEYBTDECL(0x78, 0x58, true, 45),
    /* c C */ KEYBTDECL(0x63, 0x43, true, 46),
    /* v V */ KEYBTDECL(0x76, 0x56, true, 47),
    /* b B */ KEYBTDECL(0x62, 0x42, true, 48),
    /* n N */ KEYBTDECL(0x6e, 0x4e, true, 49),
    /* m M */ KEYBTDECL(0x6d, 0x4d, true, 50),
    /* , < */ KEYBTDECL(0x2c, 0x3c, false, 51),
    /* . > */ KEYBTDECL(0x2e, 0x3e, false, 52),
    /* / ? */ KEYBTDECL(0x2f, 0x5f, false, 53)};

void UBPlatformUtils::initializeKeyboardLayouts()
{
    nKeyboardLayouts = 1;
    keyboardLayouts = new UBKeyboardLocale*[nKeyboardLayouts];
    keyboardLayouts[0] = new UBKeyboardLocale(tr("English"), "en", "", new QIcon(":/images/flags/en.png"), ENGLISH_LOCALE);
}

void UBPlatformUtils::destroyKeyboardLayouts()
{
    for (int i = 0; i < nKeyboardLayouts; i++)
        delete keyboardLayouts[i];
    delete [] keyboardLayouts;
    keyboardLayouts = NULL;
}

QString UBPlatformUtils::urlFromClipboard()
{
    return QString();
}

void UBPlatformUtils::setFrontProcess()
{
    // Not used on FreeBSD
}

void UBPlatformUtils::showFullScreen(QWidget *pWidget)
{
    if (UBSettings::settings()->appRunInWindow->get().toBool() &&
            pWidget == UBApplication::displayManager->widget(ScreenRole::Control)) {
        pWidget->show();
    } else {
        pWidget->showFullScreen();
    }
}

void UBPlatformUtils::showOSK(bool show)
{
    Q_UNUSED(show);
    // No on-screen keyboard support on FreeBSD
}
