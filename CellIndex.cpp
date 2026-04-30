#include <CellIndex.hpp>

namespace {

size_t normalizeImpl(size_t modulo, int32_t raw) {
    while (raw < 0) {
        raw += static_cast<int32_t>(modulo);
    }
    return static_cast<size_t>(raw) % modulo;
}

} // namespace

NormalizedIndex normalize(NormalizedIndex modulo, CellIndex index) {
    return {::normalizeImpl(modulo.row, index.getRawRow()),
            ::normalizeImpl(modulo.col, index.getRawCol())};
}
