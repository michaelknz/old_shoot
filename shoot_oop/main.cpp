#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "mesh_polygon.h"
#include "mesh_point.h"
#include "shader_without_gs.h"
#include "shader_with_gs.h"
#include "Parser.h"
#include "matrixes.h"
#include "event_handler.h"
#include "Textures.h"
#include "decals_maker.h"

int main(int argc, char** argv) {

	display display(800, 600, "shooter");

	Camera cam;
	cam.CameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	cam.CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cam.CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	cam.speed = 0.1f;
	float sence = 0.2f;
	std::vector<float> dels_alpha;
	float laser_dist = 10.0f;

	Textures texture;
	texture.SetTexture("hole.jpg");

	decals_maker dec_maker;

	event_handler Event_handler;
	SDL_Event Event;
	Parser parser;

	matrixes level_matrix;
	matrixes gun_matrix;
	matrixes shot_matrix;
	std::vector<matrixes*> decal_matrixes;
	Transform level_mat = level_matrix.Create_matrixes(false, false, false, cam, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f), glm::vec3(0.0f));
	Transform gun_mat = gun_matrix.Create_matrixes(false, true, true, cam, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.3f, 0.3f, 0.7f), glm::vec3(0.02f, -0.05f, -0.1f));
	Transform shot_mat = shot_matrix.Create_matrixes(false, false, false, cam, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f), glm::vec3(0.0f));
	std::vector<Transform*> decal_mat;

	parser.push_new_mesh("level.obj");
	parser.push_new_mesh("gun.obj");
	parser.push_new_mesh("decal_cube.obj");
	std::vector<float> cube_1 = parser.load_one_mesh(1);
	std::vector<float> cube_2 = parser.load_one_mesh(2);
	std::vector<float> plane = parser.load_one_mesh(0);
	std::vector<float> gun = parser.load_one_mesh(3);
	std::vector<float> decal = parser.load_one_mesh(4);

	dec_maker.Init(cube_1);

	shader level_shader(new shader_without_gs, "level_shade");
	shader gun_shader(new shader_without_gs, "gun_shade");
	shader dec_shader(new shader_without_gs, "dec_shade");
	std::vector<shader*> shot_shaders;

	mesh cube1_mesh(new mesh_polygon, &cube_1[0], cube_1.size());
	mesh cube2_mesh(new mesh_polygon, &cube_2[0], cube_2.size());
	mesh plane_mesh(new mesh_polygon, &plane[0], plane.size());
	mesh gun_mesh(new mesh_polygon, &gun[0], gun.size());
	mesh dec_mesh(new mesh_polygon, &decal[0], decal.size());
	std::vector<mesh*> shots;

	while (true) {
		if (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_QUIT)
				break;
			if (Event.type == SDL_KEYDOWN)
				cam = Event_handler.KeyDown_Handler(cam, Event,&level_mat);
			if (Event.type == SDL_MOUSEMOTION) {
				cam = Event_handler.MouseMove_Handler(cam, Event, &level_mat, sence);
			}
			if (Event.type == SDL_MOUSEBUTTONDOWN) {
				if (Event.button.button == SDL_BUTTON_LEFT) {
					Event_handler.LeftMouseDown_Handler(&shots, &shot_shaders, cam.CameraFront, cam.CameraPos + glm::vec3(0.02f, -0.05f, 0.0f), laser_dist, &dels_alpha);
					matrixes* matr = new matrixes;
					Transform* tr = new Transform;
					*tr = matr->Create_matrixes(false, true, true, cam, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.3f), dec_maker.dec_coord(cam.CameraPos + glm::vec3(0.02f, -0.05f, 0.0f), cam.CameraFront * laser_dist + (cam.CameraPos*glm::vec3(2.0f,1.0f,1.0f))) + glm::vec3(0.25f, -0.6f, 0.0f));
					decal_matrixes.push_back(matr);
					decal_mat.push_back(tr);
				}

				if (Event.button.button == SDL_BUTTON_RIGHT) {
					Event_handler.RightMouseDown_Handler();
				}
			}
		}
		display.Clear(0.5f, 0.5f, 0.5f, 1.0f);

		level_shader.bind();
		level_matrix.send_mat(level_shader.GetProgram(), level_mat);
		cube1_mesh.Draw();
		cube2_mesh.Draw();
		plane_mesh.Draw();

		gun_shader.bind();
		gun_matrix.send_mat(gun_shader.GetProgram(), gun_mat);
		gun_mesh.Draw();

		for (int i = 0; i < shot_shaders.size(); ++i) {
			if (dels_alpha[i] >= 1.0f)
				continue;
			shot_shaders[i]->bind();
			matrixes::veiw_matrix_update(&shot_mat, cam);
			shot_matrix.send_mat(shot_shaders[i]->GetProgram(), shot_mat);
			dels_alpha[i] += 0.01f;
			glUniform1f(glGetUniformLocation(shot_shaders[i]->GetProgram(), "del_alpha"), dels_alpha[i]);
			shots[i]->Draw();
		}

		dec_shader.bind();
		texture.UseTexture(dec_shader.GetProgram());
		for (int i = 0; i < decal_mat.size(); ++i) {
			matrixes::veiw_matrix_update(decal_mat[i], cam);
			decal_matrixes[i]->send_mat(dec_shader.GetProgram(), *decal_mat[i]);
			dec_mesh.Draw();
		}

		int j = 0;
		while (j < dels_alpha.size()) {
			if (dels_alpha[j] >= 1.0f) {
				dels_alpha.erase(dels_alpha.begin() + j);
				shot_shaders.erase(shot_shaders.begin() + j);
				shots.erase(shots.begin() + j);
			}
			else
				++j;
		}

		display.Swap();
	}
	return 0;
}