#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H

#include <vector>
#include <string>
#include <sstream>
#include "Vector2D.h"

template<typename T>
class TypedStream {
protected:
    std::istringstream stream;

public:
    TypedStream(const std::string& input) : stream(input) {}

    virtual TypedStream<T>& operator>>(T& val) = 0;

    std::string readToEnd() {
        std::ostringstream result;
        T val;
        while ((*this) >> val) {
            std::ostringstream temp;
            temp << val;
            result << temp.str() << " ";
        }
        return result.str();
    }

    operator bool() const {
        return !stream.eof();
    }
};

std::ostream& operator<<(std::ostream& out, const Vector2D& vec) {
    out << static_cast<std::string>(vec);
    return out;
}

#endif // TYPED_STREAM_H
