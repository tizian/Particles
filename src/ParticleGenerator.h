#pragma once

#include "ParticleData.h"

#include <SFML/Graphics.hpp>

namespace particles
{
	class ParticleGenerator
	{
	public:
		ParticleGenerator() {}
		virtual ~ParticleGenerator() {}

		virtual void generate(float dt, ParticleData *p, size_t startId, size_t endId) = 0;
	};


	class BoxPositionGenerator : public ParticleGenerator
	{
	public:
		BoxPositionGenerator() {}
		~BoxPositionGenerator() {}

		void generate(float dt, ParticleData *p, size_t startId, size_t endId);

	public:
		sf::Vector2f center{ 0.0f, 0.0f };
	    sf::Vector2f size{ 0.0f, 0.0f };
	};


	class CirclePositionGenerator : public ParticleGenerator
	{
	public:
		CirclePositionGenerator() {}
		~CirclePositionGenerator() {}

		void generate(float dt, ParticleData *p, size_t startId, size_t endId);

	public:
		sf::Vector2f center{ 0.0f, 0.0f };
		sf::Vector2f radius{ 0.0f, 0.0f };
	};


	class DiskPositionGenerator : public ParticleGenerator
	{
	public:
		DiskPositionGenerator() {}
		~DiskPositionGenerator() {}

		void generate(float dt, ParticleData *p, size_t startId, size_t endId);

	public:
		sf::Vector2f center{ 0.0f, 0.0f };
		float radius{ 0.0f };
	};


	class ColorGenerator : public ParticleGenerator
	{
	public:
		ColorGenerator() {}
		~ColorGenerator() {}

		void generate(float dt, ParticleData *p, size_t startId, size_t endId);

	public:
		sf::Color minStartCol{ sf::Color::Black };
		sf::Color maxStartCol{ sf::Color::Black };
		sf::Color minEndCol{ sf::Color::Black };
		sf::Color maxEndCol{ sf::Color::Black };
	};


	class VelocityGenerator : public ParticleGenerator
	{
	public:
		VelocityGenerator() {}
		~VelocityGenerator() {}

		void generate(float dt, ParticleData *p, size_t startId, size_t endId);

	public:
		sf::Vector2f minStartVel{ 0.0f, 0.0f };
		sf::Vector2f maxStartVel{ 0.0f, 0.0f };
	};


	class TimeGenerator : public ParticleGenerator
	{
	public:
		TimeGenerator() {}
		~TimeGenerator() {}

		void generate(float dt, ParticleData *p, size_t startId, size_t endId);

	public:
		float minTime{ 0.0f };
		float maxTime{ 0.0f };
	};
}
