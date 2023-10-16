#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <QString>
#include <QList>

namespace self{
    namespace global{
        const inline QList<QString> frpPath
        {
            "./",
            "frp_client/frpc.ini",
            "frp_client/frpc.exe"
        };

        inline bool isProcessStart {false};
        inline qint64 processPID;
    }
}

#endif // GLOBAL_HPP
