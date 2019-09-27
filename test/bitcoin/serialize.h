



// line 5
#ifndef BITCOIN_SERIALIZE_H
#define BITCOIN_SERIALIZE_H



#include <algorithm>
#include <assert.h>
#include <ios>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <stdint.h>
#include <string>
#include <string.h>
#include <utility>
#include <vector>

// #include <prevector.h>
// #include <span.h>
// line 52
/**
 * Used to acquire a non-const pointer "this" to generate bodies
 * of const serialization operations from a template
 */
template<typename T>
inline T* NCONST_PTR(const T* val)
{
    return const_cast<T*>(val);
}

// line 68
/*
 * Lowest-level serialization and conversion.
 * @note Sizes of these types are verified in the tests
 */
template<typename Stream> inline void ser_writedata8(Stream &s, uint8_t obj)
{
    s.write((char*)&obj, 1);
}

//line 169
class CSizeComputer;
//line 172
enum 
{
    // primary actions
    SER_NETWORK         = (1 << 0),
    SER_DISK            = (1 << 1),
    SER_GETHASH         = (1 << 2),
};

// line 179
//! Convert the reference base type to X, without changing constness or reference type.
template<typename X> X& ReadWriteAsHelper(X& x) { return x; }
template<typename X> const X& ReadWriteAsHelper(const X& x) { return x; }
// line 183
#define READWRITE(...) (::SerReadWriteMany(s, ser_action, __VA_ARGS__))
#define READWRITEAS(type, obj) (::SerReadWriteMany(s, ser_action, ReadWriteAsHelper<type>(obj)))
// line 186
/**
 * Implement three methods for serializable objects. These are actually wrappers over
 * "SerializationOp" template, which implements the body of each class' serialization
 * code. Adding "ADD_SERIALIZE_METHODS" in the body of the class causes these wrappers to be
 * added as members.
 */
#define ADD_SERIALIZE_METHODS                                         \
    template<typename Stream>                                         \
    void Serialize(Stream& s) const {                                 \
        NCONST_PTR(this)->SerializationOp(s, CSerActionSerialize());  \
    }                                                                 \
    template<typename Stream>                                         \
    void Unserialize(Stream& s) {                                     \
        SerializationOp(s, CSerActionUnserialize());                  \
    }

#ifndef CHAR_EQUALS_INT8
template<typename Stream> inline void Unserialize(Stream& s, char& a    ) { a = ser_readdata8(s); } // TODO Get rid of bare char
#endif
template<typename Stream> inline void Unserialize(Stream& s, int8_t& a  ) { a = ser_readdata8(s); }
template<typename Stream> inline void Unserialize(Stream& s, uint8_t& a ) { a = ser_readdata8(s); }
template<typename Stream> inline void Unserialize(Stream& s, int16_t& a ) { a = ser_readdata16(s); }
template<typename Stream> inline void Unserialize(Stream& s, uint16_t& a) { a = ser_readdata16(s); }
template<typename Stream> inline void Unserialize(Stream& s, int32_t& a ) { a = ser_readdata32(s); }
template<typename Stream> inline void Unserialize(Stream& s, uint32_t& a) { a = ser_readdata32(s); }
template<typename Stream> inline void Unserialize(Stream& s, int64_t& a ) { a = ser_readdata64(s); }
template<typename Stream> inline void Unserialize(Stream& s, uint64_t& a) { a = ser_readdata64(s); }
template<typename Stream> inline void Unserialize(Stream& s, float& a   ) { a = ser_uint32_to_float(ser_readdata32(s)); }
template<typename Stream> inline void Unserialize(Stream& s, double& a  ) { a = ser_uint64_to_double(ser_readdata64(s)); }
template<typename Stream, int N> inline void Unserialize(Stream& s, char (&a)[N]) { s.read(a, N); }
template<typename Stream, int N> inline void Unserialize(Stream& s, unsigned char (&a)[N]) { s.read(CharCast(a), N); }
// template<typename Stream> inline void Unserialize(Stream& s, Span<unsigned char>& span) { s.read(CharCast(span.data()), span.size()); }



/**
 * Support for ADD_SERIALIZE_METHODS and READWRITE macro
 */
struct CSerActionSerialize
{
    constexpr bool ForRead() const { return false; }
};
struct CSerActionUnserialize
{
    constexpr bool ForRead() const { return true; }
};



template<typename Stream>
void SerializeMany(Stream& s)
{
}

template<typename Stream, typename Arg, typename... Args>
inline void UnserializeMany(Stream& s, Arg&& arg, Args&&... args)
{
    ::Unserialize(s, arg);
    ::UnserializeMany(s, args...);
}

template<typename Stream, typename... Args>
inline void SerReadWriteMany(Stream& s, CSerActionSerialize ser_action, const Args&... args)
{
    ::SerializeMany(s, args...);
}

template<typename Stream, typename... Args>
inline void SerReadWriteMany(Stream& s, CSerActionUnserialize ser_action, Args&&... args)
{
    ::UnserializeMany(s, args...);
}

// line 202
#ifndef CHAR_EQUALS_INT8
template<typename Stream> inline void Serialize(Stream& s, char a    ) { ser_writedata8(s, a); } // TODO Get rid of bare char
#endif
template<typename Stream> inline void Serialize(Stream& s, int8_t a  ) { ser_writedata8(s, a); }


#endif // BITCOIN_SERIALIZE_H