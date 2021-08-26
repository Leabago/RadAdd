#include "filevalidator.h"

#include <QFile>
#include <QImage>

FileValidator::FileValidator(QObject *parent) :
    QObject(parent),
    mTreatAsImage(false)
{
    setFileErrorMessage("Must specify a file");
}

QUrl FileValidator::url() const
{
    return mUrl;
}

void FileValidator::setUrl(const QUrl &url)
{

    QString strUrl = "file:" + url.toString();


    if (strUrl == mUrl.toString())
           return;

      mUrl = strUrl;

//      qDebug() << "FileValidator::setUrl" ;
//      qDebug() << "mUrl: " << mUrl;
//         qDebug() << "mUrl.toLocalFile():" <<   mUrl.toLocalFile() ;



//      if (QFile::exists(mUrl.toString()))
//      {
//            qDebug() << "exist  " ;
//      } else {
//             qDebug() << "not exist  "  ;
//      }


    if (mUrl.isEmpty()) {
        setFileErrorMessage(tr("Must specify a file"));
//          qDebug() << "Must specify a file"  ;
    } else if (!QFile::exists(mUrl.toLocalFile())) {
        setFileErrorMessage(tr("File doesn't exist"));
//          qDebug() << "File doesn't exist"  ;
    } else {
        if (mTreatAsImage) {
            QImage image(mUrl.toLocalFile());
            if (image.isNull()) {
                setFileErrorMessage(tr("Image can not be opened"));
//                 qDebug() << "Image can not be opened"  ;
            } else {
                // The image was loaded successfully, so we can clear
                // whatever was here before.
                setFileErrorMessage(QString());
//                  qDebug() << "The image was loaded successfully, so we can clear"  ;
            }
        } else {
            // The file was loaded successfully.
            setFileErrorMessage(QString());
//             qDebug() << "The file was loaded successfully."  ;
        }
    }

    if (mFileErrorMessage.isEmpty()) {
        // Let derived classes check for problems.
        validate();
//           qDebug() << "The file validate"  ;
    }

    emit urlChanged();
}

bool FileValidator::isFileValid() const
{
    return mFileErrorMessage.isEmpty();
}

QString FileValidator::fileErrorMessage() const
{
    return mFileErrorMessage;
}

void FileValidator::setFileErrorMessage(const QString &fileErrorMessage)
{
    if (fileErrorMessage == mFileErrorMessage)
        return;

    bool wasValid = isFileValid();

    mFileErrorMessage = fileErrorMessage;
    if (isFileValid() != wasValid) {
        emit fileValidChanged();
    }

    emit fileErrorMessageChanged();
}

bool FileValidator::treatAsImage() const
{
    return mTreatAsImage;
}

void FileValidator::setTreatAsImage(bool treatAsImage)
{
    if (treatAsImage == mTreatAsImage)
        return;

    mTreatAsImage = treatAsImage;
    emit treatAsImageChanged();
}

void FileValidator::validate()
{
}
