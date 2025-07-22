/*
 * This source file is part of MyGUI. For the latest info, see http://mygui.info/
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#ifndef MYGUI_TEXT_VIEW_DATA_H_
#define MYGUI_TEXT_VIEW_DATA_H_

#include "MyGUI_Prerequest.h"

namespace MyGUI
{

	class CharInfo
	{
	public:

		enum class Type : uint8_t
		{
			Normal,
			Colour,
			Whitespace
		};

		CharInfo()
		{
			mMetrics.mWidth = 0.0f;
			mMetrics.mHeight = 0.0f;
			mMetrics.mAdvance = 0.0f;
			mMetrics.mBearingX = 0.0f;
			mMetrics.mBearingY = 0.0f;
		}

		CharInfo(
			const FloatRect& _rect,
			float _width,
			float _height,
			float _advance,
			float _bearingX,
			float _bearingY,
			Type eType = Type::Normal ) :
			m_eType( eType ),
			mUVRect(_rect)
		{
			mMetrics.mWidth = _width;
			mMetrics.mHeight = _height;
			mMetrics.mAdvance = _advance;
			mMetrics.mBearingX = _bearingX;
			mMetrics.mBearingY = _bearingY;
		}

		CharInfo( uint32 _colour ) :
			m_eType( Type::Colour ),
			mColour( _colour )
		{ }

		bool isColour() const
		{
			return m_eType == Type::Colour;
		}

		bool isWhitespace() const
		{
			return m_eType == Type::Whitespace;
		}

		float getWidth() const
		{
			return mMetrics.mWidth;
		}

		float getHeight() const
		{
			return mMetrics.mHeight;
		}

		float getAdvance() const
		{
			return mMetrics.mAdvance;
		}

		float getBearingX() const
		{
			return mMetrics.mBearingX;
		}

		float getBearingY() const
		{
			return mMetrics.mBearingY;
		}

		const FloatRect& getUVRect() const
		{
			return mUVRect;
		}

		uint32 getColour() const
		{
			return mColour;
		}

	private:

		Type m_eType = Type::Normal;
		
		FloatRect mUVRect;

		struct Metrics
		{
			float mWidth;
			float mHeight;
			float mAdvance;
			float mBearingX;
			float mBearingY;
		};

		union
		{
			Metrics mMetrics;
			uint32 mColour;
		};

	};

	typedef std::vector<CharInfo> VectorCharInfo;

	struct LineInfo
	{
		LineInfo() :
			width(0),
			offset(0),
			count(0)
		{
		}

		void clear()
		{
			width = 0;
			count = 0;
			symbols.clear();
			offset = 0;
		}

		int width;
		int offset;
		size_t count;
		VectorCharInfo symbols;
	};

	typedef std::vector<LineInfo> VectorLineInfo;

} // namespace MyGUI

#endif // MYGUI_TEXT_VIEW_DATA_H_
