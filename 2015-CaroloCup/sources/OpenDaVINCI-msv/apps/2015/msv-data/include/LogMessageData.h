/*
 * This software is open source. Please see COPYING and AUTHORS for further information.
 *
 * This file is auto-generated. DO NOT CHANGE AS YOUR CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef MSV_LOGMESSAGEDATA_H
#define MSV_LOGMESSAGEDATA_H

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"


#include "core/data/SerializableData.h"


namespace msv {
	using namespace std;
	
	class LogMessageData : public core::data::SerializableData {
		public:
			LogMessageData();
			LogMessageData(const string &comp);

			virtual ~LogMessageData();
	
			/**
			 * Copy constructor.
			 *
			 * @param obj Reference to an object of this class.
			 */
			LogMessageData(const LogMessageData &obj);
	
			/**
			 * Assignment operator.
			 *
			 * @param obj Reference to an object of this class.
			 * @return Reference to this instance.
			 */
			LogMessageData& operator=(const LogMessageData &obj);
	
		public:
			/**
			 * @return component.
			 */
			std::string getComponent() const;
			
			/**
			 * This method sets component.
			 *
			 * @param val Value for component.
			 */
			void setComponent(const std::string &val);
		public:
			/**
			 * @return loglevel.
			 */
			std::string getLoglevel() const;
			
			/**
			 * This method sets loglevel.
			 *
			 * @param val Value for loglevel.
			 */
			void setLoglevel(const std::string &val);
		public:
			/**
			 * @return msg.
			 */
			std::string getMsg() const;
			
			/**
			 * This method sets msg.
			 *
			 * @param val Value for msg.
			 */
			void setMsg(const std::string &val);
	
		public:
			virtual ostream& operator<<(ostream &out) const;
			virtual istream& operator>>(istream &in);
	
			virtual const string toString() const;
	
		private:
			std::string m_component;
		private:
			std::string m_loglevel;
		private:
			std::string m_msg;
	};
} // msv

#endif /*MSV_LOGMESSAGEDATA_H*/
