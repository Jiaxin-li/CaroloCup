/*
 * This software is open source. Please see COPYING and AUTHORS for further information.
 *
 * This file is auto-generated. DO NOT CHANGE AS YOUR CHANGES MIGHT BE OVERWRITTEN!
 */


#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"

#include "LogMessageData.h"

namespace msv {
	using namespace std;
	using namespace core::base;
	
	LogMessageData::LogMessageData() :
	    SerializableData()
		, m_component("")
		, m_loglevel("")
		, m_msg("")
	{}
	
	LogMessageData::LogMessageData(const string &comp):
    	    SerializableData()
    			, m_component(comp)
    			, m_loglevel("")
    			, m_msg("")
    		{}

	LogMessageData::LogMessageData(const LogMessageData &obj) :
	    SerializableData()
		, m_component(obj.m_component)
		, m_loglevel(obj.m_loglevel)
		, m_msg(obj.m_msg)
	{}
	
	LogMessageData::~LogMessageData() {}
	
	LogMessageData& LogMessageData::operator=(const LogMessageData &obj) {
		m_component = obj.m_component;
		m_loglevel = obj.m_loglevel;
		m_msg = obj.m_msg;
		return (*this);
	}
	
	std::string LogMessageData::getComponent() const {
		return m_component;
	}
	
	void LogMessageData::setComponent(const std::string &val) {
		m_component = val;
	}
	std::string LogMessageData::getLoglevel() const {
		return m_loglevel;
	}
	
	void LogMessageData::setLoglevel(const std::string &val) {
		m_loglevel = val;
	}
	std::string LogMessageData::getMsg() const {
		return m_msg;
	}
	
	void LogMessageData::setMsg(const std::string &val) {
		m_msg = val;
	}
	
	const string LogMessageData::toString() const {
		stringstream s;
	
		s << "Component: " << getComponent() << " ";
		s << "Loglevel: " << getLoglevel() << " ";
		s << "Msg: " << getMsg() << " ";
	
		return s.str();
	}
	
	ostream& LogMessageData::operator<<(ostream &out) const {
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
	
	istream& LogMessageData::operator>>(istream &in) {
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
