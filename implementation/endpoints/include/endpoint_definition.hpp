// Copyright (C) 2014-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_ENDPOINT_DEFINITION_HPP
#define VSOMEIP_ENDPOINT_DEFINITION_HPP

#include <map>
#include <memory>
#include <atomic>
#include <mutex>

#include "../../platform/platform.hpp"
#include <vsomeip/primitive_types.hpp>

#include <vsomeip/export.hpp>

namespace vsomeip {

class endpoint_definition {
public:
    VSOMEIP_EXPORT static std::shared_ptr<endpoint_definition> get(
            const platform::ip::address &_address,
            uint16_t _port, bool _is_reliable, service_t _service, instance_t _instance);

    VSOMEIP_EXPORT const platform::ip::address &get_address() const;

    VSOMEIP_EXPORT uint16_t get_port() const;

    VSOMEIP_EXPORT uint16_t get_remote_port() const;
    VSOMEIP_EXPORT void set_remote_port(uint16_t _port);

    VSOMEIP_EXPORT bool is_reliable() const;

    VSOMEIP_EXPORT endpoint_definition(
            const platform::ip::address &_address,
            uint16_t _port, bool _is_reliable);
private:
    platform::ip::address address_;
    uint16_t port_;
    std::atomic<uint16_t> remote_port_;
    bool is_reliable_;

    static std::mutex definitions_mutex_;
    static std::map<
        std::tuple<service_t, instance_t, platform::ip::address, uint16_t, bool>,
        std::shared_ptr<endpoint_definition> > definitions_;
};

} // namespace vsomeip

#endif // VSOMEIP_ENDPOINT_DEFINITION_HPP
