#pragma once

struct Transform
{
	D3DXVECTOR3 Position;	// ���W.
	D3DXVECTOR3 Rotation;	// ��].
	D3DXVECTOR3 Scale;		// �g�k.
	Transform()
		: Position	( 0.0f, 0.0f, 0.0f )
		, Rotation	( 0.0f, 0.0f, 0.0f )
		, Scale		( 1.0f, 1.0f, 1.0f )
	{}
	Transform( D3DXVECTOR3 position, D3DXVECTOR3 rotation, D3DXVECTOR3 scale )
		: Position	( position )
		, Rotation	( rotation )
		, Scale		( scale	)
	{}

	//-----------------------------------------------------------.
	// ���Z�q�I�[�o�[���[�h.
	//-----------------------------------------------------------.

	Transform operator + (const Transform& other) const
	{
		return Transform{
			Position + other.Position,
			Rotation + other.Rotation,
			Scale + other.Scale
		};
	}

	Transform operator - (const Transform& other) const
	{
		return Transform{
			Position - other.Position,
			Rotation - other.Rotation,
			Scale - other.Scale
		};
	}

	Transform operator * (const Transform& other) const
	{
		return Transform{
			Position - other.Position,
			Rotation - other.Rotation,
			Scale - other.Scale
		};
	}

	Transform operator * (const float scalar) const
	{
		return Transform{
			Position* scalar,
			Rotation* scalar,
			Scale* scalar
		};
	}

	Transform operator / (const float scalar) const
	{
		return Transform{
			Position / scalar,
			Rotation / scalar,
			Scale / scalar
		};
	}

	Transform& operator += (const Transform& other)
	{
		Position += other.Position;
		Rotation += other.Rotation;
		Scale += other.Scale;
		return *this;
	}

	Transform& operator -= (const Transform& other)
	{
		Position -= other.Position;
		Rotation -= other.Rotation;
		Scale -= other.Scale;
		return *this;
	}

	Transform& operator *= (const float scalar)
	{
		Position *= scalar;
		Rotation *= scalar;
		Scale *= scalar;
		return *this;
	}

	Transform& operator /= (const float scalar)
	{
		Position /= scalar;
		Rotation /= scalar;
		Scale /= scalar;
		return *this;
	}

	bool operator == (const Transform& other)
	{
		return	Position == other.Position &&
				Rotation == other.Rotation &&
				Scale == other.Scale;
	}

	bool operator != (const Transform & other)
	{
		return !(*this == other);
	}
};