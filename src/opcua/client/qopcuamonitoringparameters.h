/****************************************************************************
**
** Copyright (C) 2017 basysKom GmbH, opensource@basyskom.com
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtOpcUa module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QOPCUAMONITORINGPARAMETERS_H
#define QOPCUAMONITORINGPARAMETERS_H

#include <QtOpcUa/qopcuatype.h>

#include <QtCore/qshareddata.h>

QT_BEGIN_NAMESPACE

class QOpcUaMonitoringParametersPrivate;

class Q_OPCUA_EXPORT QOpcUaMonitoringParameters
{
    Q_GADGET

public:

    enum class MonitoringMode {
        Disabled = 0,
        Sampling = 1,
        Reporting = 2
    };

    enum class SubscriptionType {
        Shared,
        Exclusive
    };

    enum class Parameter {
        PublishingEnabled = (1 << 0),
        PublishingInterval = (1 << 1),
        LifetimeCount = (1 << 2),
        MaxKeepAliveCount = (1 << 3),
        MaxNotificationsPerPublish = (1 << 4),
        Priority = (1 << 5),
        SamplingInterval = (1 << 6),
        Filter = (1 << 7),
        QueueSize  = (1 << 8),
        DiscardOldest  = (1 << 9),
        MonitoringMode = (1 << 10)
    };
    Q_ENUM(Parameter)
    Q_DECLARE_FLAGS(Parameters, Parameter)

    // This type and the enums are defined in OPC-UA part 4, 7.12.2
    struct DataChangeFilter {
        enum class DataChangeTrigger {
            Status = 0,
            StatusValue = 1,
            StatusValueTimestamp = 2
        };

        enum class DeadbandType {
            None = 0,
            Absolute = 1,
            Percent = 2
        };

        DataChangeTrigger trigger;
        DeadbandType deadbandType;
        double deadbandValue;

        DataChangeFilter()
            : trigger(DataChangeTrigger::Status)
            , deadbandType(DeadbandType::None)
            , deadbandValue(0)
        {}
        DataChangeFilter(DataChangeTrigger p_trigger, DeadbandType p_deadbandType, double p_deadbandValue)
            : trigger(p_trigger)
            , deadbandType(p_deadbandType)
            , deadbandValue(p_deadbandValue)
        {}
    };

    QOpcUaMonitoringParameters();
    ~QOpcUaMonitoringParameters();
    QOpcUaMonitoringParameters(double publishingInterval, SubscriptionType shared = SubscriptionType::Shared, quint32 subscriptionId = 0);
    QOpcUaMonitoringParameters(const QOpcUaMonitoringParameters &other);
    QOpcUaMonitoringParameters &operator=(const QOpcUaMonitoringParameters &other);

    double samplingInterval() const;
    void setSamplingInterval(double samplingInterval);
    QVariant filter() const;
    void setDataChangeFilter(const QOpcUaMonitoringParameters::DataChangeFilter &filter);
    void setFilter(const QVariant &filter);
    quint32 queueSize() const;
    void setQueueSize(quint32 queueSize);
    bool discardOldest() const;
    void setDiscardOldest(bool discardOldest);
    QOpcUaMonitoringParameters::MonitoringMode monitoringMode() const;
    void setMonitoringMode(MonitoringMode monitoringMode);
    quint32 subscriptionId() const;
    void setSubscriptionId(quint32 subscriptionId);
    double publishingInterval() const;
    void setPublishingInterval(double publishingInterval);
    quint32 lifetimeCount() const;
    void setLifetimeCount(quint32 lifetimeCount);
    quint32 maxKeepAliveCount() const;
    void setMaxKeepAliveCount(quint32 maxKeepAliveCount);
    quint32 maxNotificationsPerPublish() const;
    void setMaxNotificationsPerPublish(quint32 maxNotificationsPerPublish);
    quint8 priority() const;
    void setPriority(quint8 priority);
    bool publishingEnabled() const;
    void setPublishingEnabled(bool publishingEnabled);
    QOpcUa::UaStatusCode statusCode() const;
    void setStatusCode(QOpcUa::UaStatusCode statusCode);
    QOpcUaMonitoringParameters::SubscriptionType shared() const;
    void setShared(SubscriptionType subscriptionType);
    QString indexRange() const;
    void setIndexRange(const QString &indexRange);

private:
    QSharedDataPointer<QOpcUaMonitoringParametersPrivate> d_ptr;
};

Q_DECLARE_TYPEINFO(QOpcUaMonitoringParameters::SubscriptionType, Q_PRIMITIVE_TYPE);
Q_DECLARE_TYPEINFO(QOpcUaMonitoringParameters::DataChangeFilter::DataChangeTrigger, Q_PRIMITIVE_TYPE);
Q_DECLARE_TYPEINFO(QOpcUaMonitoringParameters::DataChangeFilter::DeadbandType, Q_PRIMITIVE_TYPE);
Q_DECLARE_OPERATORS_FOR_FLAGS(QOpcUaMonitoringParameters::Parameters)

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QOpcUaMonitoringParameters)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::SubscriptionType)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::DataChangeFilter)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::DataChangeFilter::DataChangeTrigger)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::DataChangeFilter::DeadbandType)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::Parameter)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::Parameters)
Q_DECLARE_METATYPE(QOpcUaMonitoringParameters::MonitoringMode)

#endif // QOPCUAMONITORINGPARAMETERS_H
