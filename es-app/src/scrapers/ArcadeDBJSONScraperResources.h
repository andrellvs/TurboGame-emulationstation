#pragma once
#ifndef ES_APP_SCRAPERS_ARCADE_DB_JSON_SCRAPER_RESOURCES_H
#define ES_APP_SCRAPERS_ARCADE_DB_JSON_SCRAPER_RESOURCES_H

#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>

#include "HttpReq.h"


struct ArcadeDBJSONRequestResources
{
	ArcadeDBJSONRequestResources() = default;

	void prepare();
	void ensureResources();
	std::string getApiKey() const;

  private:
	bool checkLoaded();

	bool saveResource(HttpReq* req, std::unordered_map<int, std::string>& resource, const std::string& resource_name,
		const std::string& file_name);
	std::unique_ptr<HttpReq> fetchResource(const std::string& endpoint);

	int loadResource(
		std::unordered_map<int, std::string>& resource, const std::string& resource_name, const std::string& file_name);

	std::unique_ptr<HttpReq> gamesdb_developers_resource_request;
	std::unique_ptr<HttpReq> gamesdb_publishers_resource_request;
	std::unique_ptr<HttpReq> gamesdb_genres_resource_request;
};

std::string getScrapersResourceDir();

#endif // ES_APP_SCRAPERS_ARCADE_DB_JSON_SCRAPER_H
