/*
 * libiconvplus - A C++ lightweight wrapper around the iconv library.
 * Copyright (C) 2010-2011 Julien KAUFFMANN <julien.kauffmann@freelan.org>
 *
 * This file is part of libfreelan.
 *
 * libfreelan is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libfreelan is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 *
 * If you intend to use libfreelan in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file converter.hpp
 * \author Julien KAUFFMANN <julien.kauffmann@freelan.org>
 * \brief The iconv converter class.
 */

#ifndef ICONVPLUS_CONVERTER_HPP
#define ICONVPLUS_CONVERTER_HPP

#include "iconv.hpp"

#include <boost/system/error_code.hpp>

#include <iostream>
#include <vector>

namespace iconvplus
{
	/**
	 * \brief A converter class.
	 */
	class converter
	{
		public:

			/**
			 * \brief The default size of chunks.
			 */
			static const size_t DEFAULT_CHUNK_SIZE = 8192;

			/**
			 * \brief Create a new converter.
			 * \param chunk_size The chunk size.
			 *
			 * The streams must remain valid during the lifetime of the converter instance.
			 */
			converter(size_t chunk_size = DEFAULT_CHUNK_SIZE);

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param is The input stream.
			 * \param os The output stream.
			 * \param ec The error code, if an error occurs.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, ec is updated to indicate the error.
			 */
			bool convert(const iconv& ic, std::istream& is, std::ostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param is The input stream.
			 * \param os The output stream.
			 * \param ec The error code, if an error occurs.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, ec is updated to indicate the error.
			 */
			bool convert(const iconv& ic, std::wistream& is, std::ostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param is The input stream.
			 * \param os The output stream.
			 * \param ec The error code, if an error occurs.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, ec is updated to indicate the error.
			 */
			bool convert(const iconv& ic, std::istream& is, std::wostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param is The input stream.
			 * \param os The output stream.
			 * \param ec The error code, if an error occurs.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, ec is updated to indicate the error.
			 */
			bool convert(const iconv& ic, std::wistream& is, std::wostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, a boost::system::system_error is thrown.
			 */
			void convert(const iconv& ic, std::istream& is, std::ostream& os, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, a boost::system::system_error is thrown.
			 */
			void convert(const iconv& ic, std::wistream& is, std::ostream& os, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, a boost::system::system_error is thrown.
			 */
			void convert(const iconv& ic, std::istream& is, std::wostream& os, size_t* non_reversible_conversions = NULL) const;

			/**
			 * \brief Proceed to the conversion, using the specified iconv instance.
			 * \param ic The iconv instance to use.
			 * \param non_reversible_conversions If not NULL, *non_reversible_conversions will be updated to indicate the count of non-reversible conversions performed during the call.
			 * \return true on success. On error, a boost::system::system_error is thrown.
			 */
			void convert(const iconv& ic, std::wistream& is, std::wostream& os, size_t* non_reversible_conversions = NULL) const;

		private:

			template <class InputStreamType, class OutputStreamType>
			bool generic_convert(const iconv& ic, InputStreamType& is, OutputStreamType& os, boost::system::error_code& ec, size_t* non_reversible_conversions = NULL) const;

			template <class InputStreamType, class OutputStreamType>
			void generic_convert(const iconv& ic, InputStreamType& is, OutputStreamType& os, size_t* non_reversible_conversions = NULL) const;

			mutable std::vector<char> m_ibuf;
			mutable std::vector<char> m_obuf;
	};
	
	inline converter::converter(size_t chunk_size) :
		m_ibuf(chunk_size),
		m_obuf(chunk_size)
	{
	}
	
	inline bool converter::convert(const iconv& ic, std::istream& is, std::ostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions) const
	{
		return generic_convert(ic, is, os, ec, non_reversible_conversions);
	}
	
	inline bool converter::convert(const iconv& ic, std::wistream& is, std::ostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions) const
	{
		return generic_convert(ic, is, os, ec, non_reversible_conversions);
	}
	
	inline bool converter::convert(const iconv& ic, std::istream& is, std::wostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions) const
	{
		return generic_convert(ic, is, os, ec, non_reversible_conversions);
	}
	
	inline bool converter::convert(const iconv& ic, std::wistream& is, std::wostream& os, boost::system::error_code& ec, size_t* non_reversible_conversions) const
	{
		return generic_convert(ic, is, os, ec, non_reversible_conversions);
	}
	
	inline void converter::convert(const iconv& ic, std::istream& is, std::ostream& os, size_t* non_reversible_conversions) const
	{
		generic_convert(ic, is, os, non_reversible_conversions);
	}
	
	inline void converter::convert(const iconv& ic, std::wistream& is, std::ostream& os, size_t* non_reversible_conversions) const
	{
		generic_convert(ic, is, os, non_reversible_conversions);
	}
	
	inline void converter::convert(const iconv& ic, std::istream& is, std::wostream& os, size_t* non_reversible_conversions) const
	{
		generic_convert(ic, is, os, non_reversible_conversions);
	}
	
	inline void converter::convert(const iconv& ic, std::wistream& is, std::wostream& os, size_t* non_reversible_conversions) const
	{
		generic_convert(ic, is, os, non_reversible_conversions);
	}
}

#endif /* ICONVPLUS_CONVERTER_HPP */
