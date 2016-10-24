/**
 *    > Author:   UncP
 *    > Mail:     770778010@qq.com
 *    > Github:   https://www.github.com/UncP/Giraffe
 *    > Description:
 *
 *    > Created Time: 2016-10-21 13:47:42
**/

#ifndef _TEXTURE_LIGHT_HPP_
#define _TEXTURE_LIGHT_HPP_

#include <memory>

#include "../core/light.hpp"
#include "../core/texture.hpp"

namespace Giraffe {

class TextureLight : public Light
{
	public:
		TextureLight(const Point3d &position, const Vector3d &direction, const Vector3d &intensity,
			double angle, const std::shared_ptr<Texture> &texture);

		Vector3d computeLight(Isect &isect) const override;

		Vector3d illuminate(const Isect &isect) const override;

	private:

		using Light::intensity_;
		Point3d  position_;
		Vector3d direction_;
		double   cos_max_;
		Texture *texture_;
		Point3d  center_;
		double   radius_;
		double   inv2radius_;
};

} // namespace Giraffe

#endif /* _TEXTURE_LIGHT_HPP_ */