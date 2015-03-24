/*
 * This software is open source. Please see COPYING and AUTHORS for further information.
 *
 * This file is auto-generated. DO NOT CHANGE AS YOUR CHANGES MIGHT BE OVERWRITTEN!
 */


#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"

#include "generated/msv/LogMessagaData.h"

namespace msv {
	using namespace std;
	using namespace core::base;
	
	LogMessagaData::LogMessagaData() :
	    SerializableData()
		, m_component("")
		, m_loglevel("")
		, m_msg("")
	{}
	
	LogMessagaData::LogMessagaData(const LogMessagaData &obj) :
	    SerializableData()
		, m_component(obj.m_component)
		, m_loglevel(obj.m_loglevel)
		, m_msg(obj.m_msg)
	{}
	
	LogMessagaData::~LogMessagaData() {}
	
	LogMessagaData& LogMessagaData::operator=(const LogMessagaData &obj) {
		m_component = obj.m_component;
		m_loglevel = obj.m_loglevel;
		m_msg = obj.m_msg;
		return (*this);
	}
	
	std::string LogMessagaData::getComponent() const {
		return m_component;
	}
	
	void LogMessagaData::setComponent(const std::string &val) {
		m_component = val;
	}
	std::string LogMessagaData::getLoglevel() const {
		return m_loglevel;
	}
	
	void LogMessagaData::setLoglevel(const std::string &val) {
		m_loglevel = val;
	}
	std::string LogMessagaData::getMsg() const {
		return m_msg;
	}
	
	void LogMessagaData::setMsg(const std::string &val) {
		m_msg = val;
	}
	
	const string LogMessagaData::toString() const {
		stringstream s;
	
		s << "Component: " << getComponent() << " ";
		s << "Loglevel: " << getLoglevel() << " ";
		s << "Msg: " << getMsg() << " ";
	
		return s.str();
	}
	
	ostream& LogMessagaData::operator<<(ostream &out) const {
		SerializationFactory sf;
	
		Serializer &s = sf.getSerializer(out);
	
		s.write(CRC32 < CharList<'c', CharList<'o', CharList<'m', CharList<'p', CharList<'o', CharList<'n', CharList<'e', CharList<'n', CharList<'t', NullType> > > > > > > > >  >::RESULT,
				m_component);
		s.write(CRC32 < CharList<'l', CharList<'o', CharList<'g', CharList<'l', CharList<'e', CharList<'v', CharList<'e', CharList<'l', NullType> > > > > > > >  >::RESULT,
				m_loglevel);
		s.write(CRC32 < CharList<'m', CharList<'s', CharList<'g', NullType> > >  >::RESULT,
				m_msg);
		return out;
	}
	
	istream& LogMessagaData::operator>>(istream &in) {
		SerializationFactory sf;
	
		Deserializer &d = sf.getDeserializer(in);
	
		d.read(CRC32 < CharList<'c', CharList<'o', CharList<'m', CharList<'p', CharList<'o', CharList<'n', CharList<'e', CharList<'n', CharList<'t', NullType> > > > > > > > >  >::RESULT,
				m_component);
		d.read(CRC32 < CharList<'l', CharList<'o', CharList<'g', CharList<'l', CharList<'e', CharList<'v', CharList<'e', CharList<'l', NullType> > > > > > > >  >::RESULT,
				m_loglevel);
		d.read(CRC32 < CharList<'m', CharList<'s', CharList<'g', NullType> > >  >::RESULT,
				m_msg);
		return in;
	}
} // msv
