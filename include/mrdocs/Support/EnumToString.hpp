//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// Copyright (c) 2025 Gennaro Prota (gennaro.prota@gmail.com)
//
// Official repository: https://github.com/cppalliance/mrdocs
//

#ifndef MRDOCS_API_SUPPORT_ENUMTOSTRING_HPP
#define MRDOCS_API_SUPPORT_ENUMTOSTRING_HPP

#include <string>
#include <type_traits>

namespace mrdocs {

/** Convert a Boost.Describe'd enumerator to string form.

    @param e The enumerator to convert.
    @return The string form of the enumerator.
*/
template <typename Enum>
    requires std::is_enum_v<Enum>
std::string
toString(Enum e);

enum class ExtractionMode;
enum class FunctionClass;
enum class RecordKeyKind;
enum class UsingClass;

extern template std::string toString<ExtractionMode>(ExtractionMode);
extern template std::string toString<FunctionClass>(FunctionClass);
extern template std::string toString<RecordKeyKind>(RecordKeyKind);
extern template std::string toString<UsingClass>(UsingClass);

}

#endif
