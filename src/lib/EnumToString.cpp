//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// Copyright (c) 2025 Gennaro Prota (gennaro.prota@gmail.com)
//
// Official repository: https://github.com/cppalliance/mrdocs
//

#include "Reflection.hpp"
#include <mrdocs/Support/Assert.hpp>
#include <mrdocs/Support/EnumToString.hpp>
#include <mrdocs/Support/String.hpp>
#include <boost/describe/enumerators.hpp>
#include <boost/mp11.hpp>

namespace mrdocs {

template <typename Enum>
    requires std::is_enum_v<Enum>
std::string
toString(Enum e)
{
    static_assert(boost::describe::has_describe_enumerators<Enum>::value);

    std::string result;
    boost::mp11::mp_for_each<
        boost::describe::describe_enumerators<Enum>>(
        [&](auto const& D)
        {
            if (D.value == e)
            {
                result = toKebabCase(D.name);
            }
        });

    if (!result.empty())
    {
        return result;
    }

    MRDOCS_UNREACHABLE();
}

template std::string toString<ExtractionMode>(ExtractionMode);
template std::string toString<FunctionClass>(FunctionClass);
template std::string toString<RecordKeyKind>(RecordKeyKind);
template std::string toString<UsingClass>(UsingClass);

}
